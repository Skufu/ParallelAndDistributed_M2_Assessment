# Spy vs. Spy Multithreaded Simulation

A C++ program demonstrating thread synchronization and shared memory through a competitive spy simulation.

## 📖 Description
Two spies (Spy 1 and Spy 2) compete to collect gold from a shared resource pool while sabotaging each other. The program uses:
- **Threads** for concurrent spy actions
- **Mutexes** for safe shared memory access
- **Randomized behavior** for dynamic interactions

## ✨ Features
- **3 Threads**  
  👥 Spy 1 & Spy 2 (competing)  
  🔄 Resource Manager (periodically refills resources)
- **Shared Memory**  
  🪙 Gold pool  
  ⚔️ Weapons inventory
- **Actions**  
  Collect | Steal | Defend

## ⚙️ Requirements
- C++11 compatible compiler (GCC/Clang)
- Linux/macOS (tested on Ubuntu 22.04/macOS Ventura)

## 🚀 How to Run
1. Compile: g++ -std=c++11 main.cpp spy_vs_spy.cpp -o spy_game -pthread
2. Execute: ./spy_game
