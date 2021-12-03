#include "rand_int.h"

int rand_int()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}