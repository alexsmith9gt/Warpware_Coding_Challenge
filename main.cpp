#include <vector>
#include <iostream>
#include "coin.h"
#include <tuple>
#include <unordered_map>

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
std::tuple<int, int, std::vector<Coin>> qualifier_Round(std::vector<Coin>& coins, int flips_per, int coins_returning){
    int max_heads = 0;
    int flips = 0;
    int heads = 0;
    std::vector<Coin> best_coins{};
    std::unordered_map<int, std::vector<Coin>> heads_count_map{};

    for(Coin& coin: coins){
        int num_heads = coin.flip_Sequence(flips_per);
        flips += flips_per;
        heads += num_heads;

        // Collecting the coins with the most heads
        if(num_heads > max_heads){
            max_heads = num_heads;
        }
        // this specific count not found yet
        if(heads_count_map.find(num_heads) == heads_count_map.end()){
            heads_count_map[num_heads] = std::vector<Coin> {coin};
        }
        // heads count already found
        else{
            heads_count_map[num_heads].push_back(coin);
        }
    }
    int temp_heads = max_heads;
    std::mt19937 gen(std::random_device{}());
    while(best_coins.size() < coins_returning){
        if(heads_count_map.find(temp_heads) == heads_count_map.end()){
            temp_heads--;
        }
        else{
            // std::cout << heads_count_map[temp_heads].size() << '\n';
            std::uniform_int_distribution<> dis(0, heads_count_map[temp_heads].size() - 1);
            int i = dis(gen);
            best_coins.push_back(heads_count_map[temp_heads][i]);
            heads_count_map[temp_heads].erase(heads_count_map[temp_heads].begin() + i);

            // ran out of coins at the number of heads
            if(heads_count_map[temp_heads].size() == 0) temp_heads--;     
        }
    }
    return{flips, heads, best_coins};
}

// Function for performing one run of 20 flips
// Returns number of heads flipped
int one_Run(){
    std::vector<Coin> coins = build_Coins();
    // First qualifying round
    auto [num_flips, num_heads, best_coins] = qualifier_Round(coins, 2, 2);
    // std::cout << num_heads << "Out of " << num_flips << '\n';

    // Second qualifying round
    auto [additional_flips, additional_heads, new_best] = qualifier_Round(best_coins, 1, 1);
    // std::cout << additional_heads << "Out of " << additional_flips << '\n';
    num_heads += additional_heads;
    num_flips += additional_flips;
    num_heads += best_coins[0].flip_Sequence((20-num_flips));
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
    // int num_heads = one_Run();
    // std::cout << "The number of heads was " << num_heads << '\n';
    one_Hundred_Runs();
    return 0;
}