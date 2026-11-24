#ifndef COIN_H
#define COIN_H
#include <random>
#include <vector>
class Coin{
    private:
    double chance_heads;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
    
    public:
    Coin(double chance);
    bool flip_Coin();
    int flip_Sequence(int flips);
    double get_chance_heads();
};


#endif