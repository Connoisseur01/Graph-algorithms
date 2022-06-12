#pragma once
#include <chrono>

class Counter{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startPoint, stopPoint;
        std::chrono::high_resolution_clock clock;
    public:

        Counter();

        void startCounter();
        void stopCounter();

        double getCounter();
};