#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {
public:
    Random() = delete;

    static int getRandom(int min, int max);

    static int getRandom(int max);

private:
    static std::mt19937 engine;
};

#endif //RANDOM_H
