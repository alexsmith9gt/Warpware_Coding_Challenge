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

// Function for performing the qualifier round and selecting the best coin
// Returns a tuple containing number of flips performed, number of heads recorded and the best coin 
std::tuple<int, int, Coin> qualifier_Round(std::vector<Coin>& coins){
    int max_heads = 0;
    int flips = 0;
    int heads = 0;
    int flips_per = 2; //Can be changed in testing
    std::vector<Coin> best_coins{};

    for(Coin& coin: coins){
        int num_heads = coin.flip_Sequence(flips_per);
        flips += flips_per;
        heads += num_heads;

        // Collecting the coins with the most heads
        if(num_heads > max_heads){
            max_heads = num_heads;
            best_coins = {coin};
        }
        else if(num_heads == max_heads){
            best_coins.push_back(coin);
        }
    }
    if(best_coins.size() == 1){
        return{flips, heads, best_coins[0]};
    }
    // pick random coin in best_coins
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(0, best_coins.size() - 1);
    return{flips, heads, best_coins[dis(gen)]};
}

// Function for performing one run of 20 flips
// Returns number of heads flipped
int one_Run(){
    std::vector<Coin> coins = build_Coins();
    auto [num_flips, num_heads, best_coin] = qualifier_Round(coins);
    // std::cout << num_heads << "Out of " << num_flips << '\n';
    num_heads += best_coin.flip_Sequence(20-num_flips);
    return num_heads;

}

// Function for performin 100 runs of 20 flips and collecting/producing data from the 100 runs
// Returns nothing but prints out the data
void one_Hundred_Runs(){
    int num_runs = 100;
    int total_heads = 0;
    int max_heads = 0;
    int min_heads = 20;
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
    one_Hundred_Runs();
    return 0;
}