/*
 * GLCM Texture Analyzer
 * Author: Yasmine Elsisi
 * Date: April 2025
 * 
 * Description:
 * This C++ program computes the Gray Level Co-occurrence Matrix (GLCM) for a grayscale image
 * and calculates texture features such as contrast, energy, and homogeneity.
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int rows, cols;
    ifstream input("sample-input.txt");
    if (!input) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    input >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    int max_gray = 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            input >> matrix[i][j];
            max_gray = max(max_gray, matrix[i][j]);
        }

    // Initialize GLCM matrix
    vector<vector<int>> glcm(max_gray + 1, vector<int>(max_gray + 1, 0));

    // Compute GLCM for direction θ = 0 (horizontal, right neighbor)
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols - 1; ++j)
            glcm[matrix[i][j]][matrix[i][j + 1]]++;

    // Normalize GLCM
    double total = 0;
    for (auto& row : glcm)
        for (int val : row)
            total += val;

    vector<vector<double>> norm_glcm(max_gray + 1, vector<double>(max_gray + 1));
    for (int i = 0; i <= max_gray; ++i)
        for (int j = 0; j <= max_gray; ++j)
            norm_glcm[i][j] = glcm[i][j] / total;

    // Compute texture features
    double contrast = 0, energy = 0, homogeneity = 0;
    for (int i = 0; i <= max_gray; ++i)
        for (int j = 0; j <= max_gray; ++j) {
            double p = norm_glcm[i][j];
            contrast += (i - j) * (i - j) * p;
            energy += p * p;
            homogeneity += p / (1 + abs(i - j));
        }

    cout << fixed << setprecision(4);
    cout << "Contrast: " << contrast << endl;
    cout << "Energy: " << energy << endl;
    cout << "Homogeneity: " << homogeneity << endl;

    return 0;
}
