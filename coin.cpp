#include "Coin.h"
#include <random>
#include <iostream>
// Throughout all programs Heads will be denoted as true (1)
// and Tails will be denoted as false (0).

Coin::Coin(double chance)
    : chance_heads{chance},
        gen(std::random_device{}()),
        dis(0.0,1.0) {}
bool Coin::flip_Coin(){
    double result = dis(gen);
    return chance_heads > result;
}
std::vector<bool> Coin::flip_Sequence(int flips){
    std::vector<bool> results;
    for(int i = 0; i < flips; i++){
        bool result = flip_Coin();
        std::cout << result << ' ';
        results.push_back(result);
    }
    std::cout << '\n';
    return results;
}
double Coin::get_chance_heads(){
    return chance_heads;
}

