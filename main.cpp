#include <vector>
#include <iostream>
#include "coin.h"

int main(){
    std::vector<double> probabilities{0.2,0.4,0.5,0.6,0.8};
    std::vector<Coin> coins;
    for(double prob : probabilities){
        coins.push_back(Coin(prob));
    }
    for(Coin coin : coins){
        std::cout << "Probability is " << 100*coin.get_chance_heads() << "%\n";
        for(int i = 0; i < 3; i++){
            std::cout << "Run " << i << ":\n";
            coin.flip_Sequence(10);
        }
    }
    return 0;
}