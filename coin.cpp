#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <iostream>


// Throughout all programs Heads will be denoted as true (1)
// and Tails will be denoted as false (0).

class Coin{
    private:
    double chance_heads;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

    public:
    Coin(double chance)
        : chance_heads{chance},
          gen(std::random_device{}()),
          dis(0.0,1.0) {}
    bool flip_Coin(){
        double result = dis(gen);
        return chance_heads > result;
    }
    std::vector<bool> flip_Sequence(int flips){
        std::vector<bool> results;
        for(int i = 0; i < flips; i++){
            bool result = flip_Coin();
            std::cout << result << ' ';
            results.push_back(result);
        }
        return results;
    }
};

int main(){
    Coin twenty(0.2);
    twenty.flip_Sequence(10);
    return 0;
}