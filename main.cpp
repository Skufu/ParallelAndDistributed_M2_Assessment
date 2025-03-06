#include "spy_vs_spy.h"

int main() {
    srand(time(nullptr));
    
    Resources pool;
    Spy spy1, spy2;
    std::mutex mtx;

    // Use lambda to handle string argument safely
    std::thread t1([&] { spyAction(spy1, spy2, pool, mtx, "SPY 1"); });
    std::thread t2([&] { spyAction(spy2, spy1, pool, mtx, "SPY 2"); });
    std::thread t3(refillResources, std::ref(pool), std::ref(mtx));

    t1.join();
    t2.join();
    t3.join();

    std::cout << "\n=== FINAL RESULTS ===\n"
              << "Spy 1: " << spy1.gold << " gold\n"
              << "Spy 2: " << spy2.gold << " gold\n"
              << "Remaining resources: " << pool.gold << " gold\n";
}
