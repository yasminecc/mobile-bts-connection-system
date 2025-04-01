
### **Step 1: Problem Identification and Statement**

Design a system to connect multiple Mobile Stations (MS) to their closest Base Transceiver Station (BTS) within a Base Station Controller (BSC).  
- Each BTS has 8 time slots available.
- If the closest BTS is full, the MS connects to the **second closest**.
- The MS must **automatically switch** to the nearest BTS as it moves (handover).

---

### **Step 2: Gathering Information**

- Each BTS has 8 time slots for MS connections.
- Distance between MS and BTS is calculated using the 3D Euclidean formula:  
  \[ d = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2 + (z_1 - z_2)^2} \]
- MS connects to the **nearest available BTS**. If none are available, the system prints:  
  `"no available BTS for ID: <MS_ID>"`.
- MS movement should trigger a **handover** to the nearest BTS with available slots.

---

### **Step 3: Test Cases**

✅ **All test cases use 1 BSC**

**Test 1 – Basic Assignment:**
- BTS1: (1,1,1), BTS2: (10,10,10), BTS3: (100,100,100)
- 5 MS devices assigned to the closest BTS based on Euclidean distance.

**Test 2 – MS Handover Movement:**
- Move MS1 to (220, 330, 440) → It should switch to BTS3 automatically.

**Test 3 – Full BTS Fallback:**
- Fill BTS1 with 8 MS devices. Add MS9 → It should connect to BTS2 as the second closest.

**Test 4 – No Available BTS:**
- Use only BTS1 and fill all 8 slots.
- Add MS9 → Should print: `no available BTS for ID: 9`.

---

### **Step 4: Algorithm Overview**

#### Class: `Position`
- Handles 3D coordinates and distance calculation.
- Methods: `setpos`, `getx/y/z`, `distance(Position)`

#### Class: `IDGenerator`
- Static method `getid()` returns a unique integer ID per object.

#### Class: `BaseTransceiverStation`
- Stores ID, position, slots array, frequency, and number of MS.
- Key methods:
  - `isempty()` → check for available slots.
  - `joinBTS(int MSID)` / `leaveBTS(int MSID)`
  - `availableslots()`, `printslots()`, `getpos()`, etc.

#### Class: `BaseStationController`
- Stores up to 100 BTS objects in an array.
- Adds new BTS and retrieves BTS array.
- Method `printBTSinfo()` displays all BTS data.

#### Class: `MobileStation`
- Represents a user device.
- On construction:
  - Connects to nearest BTS with a free slot.
  - If no BTS is available, prints a message.
- `moveMS(x, y, z)` triggers position update and automatic reassignment.
- `updateActiveBts(...)` determines the closest BTS with a slot and reassigns if needed.

---

### **Step 5: Code Implementation**

The code is implemented in C++ and follows OOP principles, using classes for encapsulation and dynamic memory for managing BTS and MS connections.

Highlights:
- Use of `static` IDs to uniquely track MS and BTS instances.
- Accurate distance calculation using `Position::distance()`.
- Efficient handover mechanism on MS movement.
- Dynamic BTS reassignment and graceful handling of full-capacity edge cases.

---

### **Step 6: Test and Verification**

✅ **Test 1:** MS1–MS5 connected to their nearest BTS based on distance  
✅ **Test 2:** MS1 moved to a distant location and successfully reassigned to BTS3  
✅ **Test 3:** BTS1 at capacity; MS9 correctly assigned to BTS2  
✅ **Test 4:** Only one BTS available and full; system prints:  
```text
no available BTS for ID: 9
```

All logic and output were verified through simulation using multiple `main()` test scenarios provided in the code.
