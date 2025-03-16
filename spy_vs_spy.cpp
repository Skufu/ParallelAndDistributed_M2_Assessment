#include "spy_vs_spy.h"

void spyAction(Spy& self, Spy& enemy, Resources& pool, std::mutex& mtx, const char* spyName) {
    // Each spy performs 10 actions
    for (int i = 0; i < 10; ++i) {
        // CRITICAL SECTION START - Lock the mutex to safely access shared resources
        mtx.lock();
        
        // Randomly choose an action (0=Collect, 1=Steal, 2=Defend)
        int action = rand() % 3;
        
        // Display current state before action
        std::cout << "\n[THREAD " << spyName << "] Current state before action:\n";
        std::cout << "  - Pool: " << pool.gold << " gold | " << spyName << ": " << self.gold 
                  << " gold | Enemy: " << enemy.gold << " gold\n";
        std::cout << "  - Attempting action: ";
        
        switch(action) {
            case 0:  // Collect from resource pool
                std::cout << "COLLECT\n";
                if(pool.gold > 0) {
                    int collected = 1 + rand() % 5;  // Random amount between 1-5
                    // Ensure we don't collect more than available
                    collected = std::min(collected, pool.gold);
                    self.gold += collected;
                    pool.gold -= collected;
                    std::cout << "  ✓ " << spyName << " collected " << collected << " gold from the pool\n";
                } else {
                    std::cout << "  ✗ Collection failed - pool is empty\n";
                }
                break;
                
            case 1:  // Steal from enemy spy
                std::cout << "STEAL\n";
                if(enemy.gold > 0) {
                    int stolen = 1 + rand() % 3;  // Random amount between 1-3
                    // Ensure we don't steal more than enemy has
                    stolen = std::min(stolen, enemy.gold);
                    enemy.gold -= stolen;
                    self.gold += stolen;
                    std::cout << "  ✓ " << spyName << " stole " << stolen << " gold from enemy\n";
                } else {
                    std::cout << "  ✗ Theft failed - enemy has no gold\n";
                }
                break;
                
            case 2:  // Defend (no action, just a strategic pause)
                std::cout << "DEFEND\n";
                std::cout << "  ✓ " << spyName << " is defending (no gold change)\n";
                break;
        }
        
        // Display state after action
        std::cout << "  - State after action: " << spyName << ": " << self.gold 
                  << " gold | Enemy: " << enemy.gold << " gold | Pool: " << pool.gold << " gold\n";
        
        // CRITICAL SECTION END - Release the mutex
        mtx.unlock();
        
        // Sleep to simulate work and make output readable
        // This happens outside the critical section to improve concurrency
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void refillResources(Resources& pool, std::mutex& mtx) {
    // Refill resources 3 times during the simulation
    for (int i = 0; i < 3; ++i) {
        // Wait a bit before refilling to let spies deplete resources
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        // CRITICAL SECTION START - Lock the mutex to safely modify shared resources
        mtx.lock();
        
        // Record values before refill
        int oldGold = pool.gold;
        int oldWeapons = pool.weapons;
        
        // Add random amounts to the resource pool
        int addedGold = 10 + rand() % 20;     // Random amount between 10-29
        int addedWeapons = 5 + rand() % 10;   // Random amount between 5-14
        
        pool.gold += addedGold;
        pool.weapons += addedWeapons;
        
        std::cout << "\n[THREAD RESOURCE MANAGER] RESOURCES REFILLED!\n";
        std::cout << "  - Gold: " << oldGold << " → " << pool.gold << " (+" << addedGold << ")\n";
        std::cout << "  - Weapons: " << oldWeapons << " → " << pool.weapons << " (+" << addedWeapons << ")\n";
        
        // CRITICAL SECTION END - Release the mutex
        mtx.unlock();
    }
}
