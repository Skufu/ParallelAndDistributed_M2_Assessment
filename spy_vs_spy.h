#ifndef SPY_VS_SPY_H
#define SPY_VS_SPY_H

#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>

struct Resources {
    int gold;
    int weapons;
    
    Resources() : gold(100), weapons(50) {}  // Constructor initialization
};

struct Spy {
    int gold;
    int weapons;
    
    Spy() : gold(0), weapons(0) {}  // Constructor initialization
};

void spyAction(Spy& self, Spy& enemy, Resources& pool, std::mutex& mtx, const char* spyName);
void refillResources(Resources& pool, std::mutex& mtx);

#endif
