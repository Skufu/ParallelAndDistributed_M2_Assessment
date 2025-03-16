#ifndef SPY_VS_SPY_H
#define SPY_VS_SPY_H

#include <iostream>    // For input/output operations
#include <thread>      // For creating and managing threads
#include <mutex>       // For thread synchronization (mutex)
#include <cstdlib>     // For rand() and srand()
#include <ctime>       // For time() function
#include <algorithm>   // For std::min function

/**
 * @brief Shared resource pool that both spies can access
 * 
 * This struct represents a shared memory region that multiple
 * threads will access concurrently, requiring synchronization.
 */
struct Resources {
    int gold;      // Gold available in the resource pool
    int weapons;   // Weapons available in the resource pool
    
    // Constructor initializes the resource pool with starting values
    Resources() : gold(100), weapons(50) {}
};

/**
 * @brief Represents a spy agent in the simulation
 * 
 * Each spy has their own inventory of collected resources.
 * These are thread-local to each spy thread but can be
 * modified by other threads during "steal" operations.
 */
struct Spy {
    int gold;      // Gold collected by this spy
    int weapons;   // Weapons collected by this spy
    
    // Constructor initializes the spy with empty inventory
    Spy() : gold(0), weapons(0) {}
};

/**
 * @brief Main action function for each spy thread
 * 
 * This function contains the logic for spy actions (collect, steal, defend)
 * and demonstrates proper mutex usage for thread synchronization.
 * 
 * @param self Reference to the current spy's data
 * @param enemy Reference to the enemy spy's data
 * @param pool Reference to the shared resource pool
 * @param mtx Reference to the mutex for synchronization
 * @param spyName Name identifier for the spy (for logging)
 */
void spyAction(Spy& self, Spy& enemy, Resources& pool, std::mutex& mtx, const char* spyName);

/**
 * @brief Resource manager thread function
 * 
 * This function periodically refills the shared resource pool,
 * demonstrating another thread that requires synchronized access
 * to the shared data.
 * 
 * @param pool Reference to the shared resource pool
 * @param mtx Reference to the mutex for synchronization
 */
void refillResources(Resources& pool, std::mutex& mtx);

#endif
