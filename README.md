# Warpware_Coding_Challenge
This is the single_qualifier branch of the repository I used to complete the Warpware Coding Challenge.

# Comments on the Code

## How to Run
Compile the program with:

    g++  .\main.cpp .\Coin.cpp -o main

Then run the program with:

    .\main

## Algorithm Description
This code implements the original version an algorithm I dubbed "Double Qualifier". Exact numbers on the number of flips per round can be tweaked but the best numbers I found involved.

- Build the coins and store them in a vector.
- Flip each coin once.
- Randomly choose two coins from those that had the most heads.
- Flip those two twice each and select random from those that had the most heads.

### Idea behind the algorithm
The second qualifying round narrows down the pool a bit more while flipping what are hopefully higher probability coins


## Implementation
The code is split into three files
- main.cpp: Implements the process of performing the algorithm on one run, performing 100 runs and it's data collection/production, and the terminal commands.
- Coin.cpp: Houses the Coin class and holds methods to perform the weighted coin flips and a sequence of them.
- Coin.h: The header file that declares the Coin class and all of its relevant functions and members.

