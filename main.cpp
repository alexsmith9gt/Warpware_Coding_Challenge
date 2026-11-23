#include <vector>
#include <iostream>
#include "coin.h"
#include <tuple>

// Function for building the 5 coins
// Returns vector with the 5 coins
std::vector<Coin> build_Coins(){
    std::vector<double> probabilities{0.2,0.4,0.5,0.6,0.8};
    std::vector<Coin> coins;
    for(double prob : probabilities){
        coins.push_back(Coin(prob));
    }
    return coins;
}

// Function for performing one run of 20 flips
// Returns number of heads flipped
int one_Run(){
    std::vector<Coin> coins = build_Coins();
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(0, coins.size() - 1);
    int num_heads = 0;
    int num_flips = 20;
    int hot_hand = dis(gen);
    for(int i = 0; i < num_flips; i++){
        if(coins[hot_hand].flip_Coin()){
            num_heads++;
        }
        else{
            hot_hand = dis(gen);
        }
    }
    // std::cout << num_heads << "Out of " << num_flips << '\n';
    return num_heads;

}

// Function for performin 100 runs of 20 flips and collecting/producing data from the 100 runs
// Returns nothing but prints out the data
void one_Hundred_Runs(){
    int num_runs = 100;
    int total_heads = 0;
    int max_heads = 0;
    int min_heads = 0;
    int above_average = 0;
    int below_average = 0;
    int heads;
    for(int i = 0; i < num_runs; i++){
        heads = one_Run();
        if(heads > max_heads) max_heads = heads;
        if(heads < min_heads) min_heads = heads;
        if(heads > 10) above_average++;
        if(heads < 10) below_average++;
        total_heads += heads;
    }
    std::cout << num_runs << " trials of 20 coin flips have been run.\nThese are the results:\n";
    std::cout << "The mean number of heads was " << static_cast<double>(total_heads)/num_runs << '\n';
    std::cout << "The max number of heads was " << max_heads << '\n';
    std::cout << "The min number of heads was " << min_heads << '\n';
    std::cout << "The number of runs with more than 10 heads was " << above_average << '\n';
    std::cout << "The number of runs with less than 10 heads was " << below_average << '\n';

}
int main(){
    // int num = one_Run();
    one_Hundred_Runs();
    return 0;
}