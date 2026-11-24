#include <vector>
#include <iostream>
#include <random>
#include "Coin.h"


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
    // starting with a random coin
    int hot_hand = dis(gen);
    // vector holding the indices of non-removed coins
    std::vector<int> available = {0,1,2,3,4};
    // array for holding the plus minus of each value by index
    int plus_minus[5] {};

    for(int i = 0; i < num_flips; i++){
        if(coins[hot_hand].flip_Coin()){
            num_heads++;
            plus_minus[hot_hand]++;
        }
        else{
            plus_minus[hot_hand]--;
            int temp = hot_hand;
            // get rid of particularly bad coins
            if(plus_minus[hot_hand] <= -4){
                std::erase(available, hot_hand);
            }
            // reinstate available set because there's no available coins left
            if(available.size() == 1){
                available = {0,1,2,3,4};
                for(int i = 0; i < 5; i++){
                    plus_minus[i] = 0;
                }
            }
            // don't remove after one mistep
            if(plus_minus[hot_hand] < 1){
                std::uniform_int_distribution<> dis(0, available.size() - 1);
                // guarantees coin isn't set to current
                while(temp == hot_hand){
                    temp = dis(gen);
                }
                hot_hand = temp;
            }
        }
    }
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
    std::cout << "Welcome to Alex Smith's Solution to the Warpware Coding Challenge!\n";
    std::cout << "This program is implementing the Hot Hand solution with a plus/minus alteration.\n";
    bool back_out = false;
    char response;
    while(!back_out){
        std::cout << "\nPress \'q\' and Enter to end the program or \'r\' and Enter to run another trial:\n";
        std::cin >> response;
        if(response == 'r'){
            one_Hundred_Runs();
        }
        else if(response == 'q'){
            back_out = true;
        }
        else{
            std::cout << "Invalid input, please try again";
        }
    }
    return 0;
}