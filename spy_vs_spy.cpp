#include "spy_vs_spy.h"

void spyAction(Spy& self, Spy& enemy, Resources& pool, std::mutex& mtx, const char* spyName) {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        int action = rand() % 3;
        
        switch(action) {
            case 0:  // Collect
                if(pool.gold > 0) {
                    int collected = 1 + rand() % 5;
                    self.gold += collected;
                    pool.gold -= collected;
                    std::cout << spyName << " collected " << collected << " gold\n";
                }
                break;
                
            case 1:  // Steal
                if(enemy.gold > 0) {
                    int stolen = 1 + rand() % 3;
                    enemy.gold -= stolen;
                    self.gold += stolen;
                    std::cout << spyName << " stole " << stolen << " gold\n";
                }
                break;
                
            case 2:  // Defend
                std::cout << spyName << " is defending\n";
                break;
        }
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void refillResources(Resources& pool, std::mutex& mtx) {
    for (int i = 0; i < 3; ++i) {
        mtx.lock();
        pool.gold += 10 + rand() % 20;
        pool.weapons += 5 + rand() % 10;
        std::cout << "\nRESOURCES REFILLED! Gold: " << pool.gold << "\n";
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
