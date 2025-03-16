# Spy vs. Spy Multithreaded Simulation

A C++ educational program demonstrating thread synchronization, mutexes, and shared memory concepts through an engaging spy simulation.

## 📖 Description

This program simulates two spies competing to collect gold from a shared resource pool while attempting to steal from each other. It serves as a practical demonstration of key multithreading concepts:

- **Concurrent Execution**: Multiple threads running simultaneously
- **Thread Synchronization**: Using mutexes to prevent data races
- **Shared Resources**: Managing access to common memory
- **Critical Sections**: Protecting data integrity during concurrent access

## 🧠 Educational Concepts Demonstrated

### 1. Thread Creation and Management
The program creates three separate threads that run concurrently:
- Two spy threads (competitors)
- One resource manager thread (environment)

### 2. Mutex (Mutual Exclusion)
- Prevents multiple threads from accessing shared data simultaneously
- Implemented using `std::mutex` from the C++ Standard Library
- Demonstrates proper locking/unlocking patterns

### 3. Critical Sections
- Code sections that access shared resources
- Protected by mutex locks to ensure thread safety
- Shows how to minimize critical section size for better performance

### 4. Race Conditions
- Demonstrates potential issues when threads compete for resources
- Shows how proper synchronization prevents data corruption

### 5. Thread Joining
- Demonstrates waiting for threads to complete using `join()`
- Shows proper program termination after all threads finish

## ✨ Features

- **3 Concurrent Threads**  
  👤 **Spy 1 Thread**: Performs actions to collect gold and compete
  👤 **Spy 2 Thread**: Competes against Spy 1 for resources
  🔄 **Resource Manager Thread**: Periodically refills the resource pool

- **Thread-Safe Actions**  
  🔹 **Collect**: Take gold from the shared resource pool
  🔹 **Steal**: Take gold from the enemy spy
  🔹 **Defend**: Strategic pause (no action)

- **Detailed Logging**  
  🔹 Shows thread states before and after actions
  🔹 Clearly indicates mutex locks and unlocks
  🔹 Visualizes resource changes

## ⚙️ Requirements

- C++11 compatible compiler (GCC/Clang)
- Linux/macOS (tested on Ubuntu 22.04/macOS Ventura)

## 🚀 How to Run

1. **Compile the program**:
   ```bash
   g++ -std=c++11 main.cpp spy_vs_spy.cpp -o spy_game -pthread
   ```

2. **Run the simulation**:
   ```bash
   ./spy_game
   ```

## 🔍 Code Structure

- **main.cpp**: Entry point, thread creation and management
- **spy_vs_spy.h**: Data structures and function declarations
- **spy_vs_spy.cpp**: Implementation of spy actions and resource management

## 🧪 Experiment Ideas

1. Try removing the mutex locks to observe race conditions
2. Modify the sleep durations to see how timing affects outcomes
3. Add more types of actions or resources
4. Implement a more sophisticated stealing mechanism (chance of failure)
5. Add a third spy to increase competition
