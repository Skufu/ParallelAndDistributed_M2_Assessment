#include "spy_vs_spy.h"

int main() {
    // Initialize random number generator with current time as seed
    srand(time(nullptr));
    
    // Create shared resources and spy objects
    Resources pool;  // Shared resource pool (initially 100 gold, 50 weapons)
    Spy spy1, spy2;  // Two competing spies (initially 0 gold, 0 weapons)
    
    // Create a mutex for thread synchronization
    // This prevents data races when multiple threads access shared data
    std::mutex mtx;

    std::cout << "=== SPY VS SPY MULTITHREADED SIMULATION ===\n";
    std::cout << "This program demonstrates thread synchronization using mutexes.\n";
    std::cout << "Watch as three threads interact with shared resources:\n";
    std::cout << "- Two spy threads competing for gold\n";
    std::cout << "- One resource manager thread refilling the pool\n\n";
    std::cout << "Starting simulation...\n\n";

    // Create three threads:
    // 1. Thread for Spy 1 actions
    // 2. Thread for Spy 2 actions
    // 3. Thread for resource pool management
    
    // Lambda functions capture references to all necessary objects
    std::thread t1([&] { spyAction(spy1, spy2, pool, mtx, "SPY 1"); });
    std::thread t2([&] { spyAction(spy2, spy1, pool, mtx, "SPY 2"); });
    
    // std::ref is needed when passing references to thread constructor
    std::thread t3(refillResources, std::ref(pool), std::ref(mtx));

    // Wait for all threads to complete before continuing
    // This is called "joining" the threads
    t1.join();
    t2.join();
    t3.join();

    // Display final results after all threads have completed
    std::cout << "\n=== SIMULATION COMPLETE ===\n";
    std::cout << "Final Results:\n";
    std::cout << "- Spy 1: " << spy1.gold << " gold\n";
    std::cout << "- Spy 2: " << spy2.gold << " gold\n";
    std::cout << "- Remaining in pool: " << pool.gold << " gold\n";
    
    // Determine the winner
    if (spy1.gold > spy2.gold) {
        std::cout << "\nSpy 1 wins by " << (spy1.gold - spy2.gold) << " gold!\n";
    } else if (spy2.gold > spy1.gold) {
        std::cout << "\nSpy 2 wins by " << (spy2.gold - spy1.gold) << " gold!\n";
    } else {
        std::cout << "\nIt's a tie! Both spies have " << spy1.gold << " gold.\n";
    }
    
    return 0;
}
