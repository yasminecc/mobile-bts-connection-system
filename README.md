# BTS–MS Handover System

This project simulates a cellular network handover system where Mobile Stations (MS) connect to the nearest Base Transceiver Station (BTS) managed by a Base Station Controller (BSC).

###  Features
- Each BTS has 8 time slots to connect to MS devices.
- MS connects to the closest available BTS.
- If full, MS connects to the next closest.
- On movement, MS automatically reassigns (handover) to a new BTS.
- Graceful handling of capacity limits.

---

##  How It Works

- Distance is calculated using 3D Euclidean formula.
- BTS and MS are modeled using C++ classes.
- MS objects dynamically switch BTS if they move.
- Slots are tracked and reassigned as needed.

---

##  Compile and Run

Make sure you have a C++ compiler (like `g++`), then:

```bash
g++ -o bts_handover main.cpp
./bts_handover
```

---

##  Files

- `main.cpp` – Source code for simulation
- `report.md` – Algorithm and testing description
- `.gitignore` – Keeps the repo clean

---

##  Author

Yasmine Elsisi – [GitHub](https://github.com/YasmineElsisi)
