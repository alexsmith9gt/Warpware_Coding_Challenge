# Warpware_Coding_Challenge
This is the single_qualifier branch of the repository I used to complete the Warpware Coding Challenge.

# Comments on the Code

## How to Run
Compile the program with:

    g++  .\main.cpp .\Coin.cpp -o main

Then run the program with:

    .\main

## Algorithm Description
This code implements the original version an algorithm I dubbed "Single Qualifier".

- Build the coins and store them in a vector.
- Flip each coin twice
- Randomly choose a coin from those that had the most heads
- Flip that coin 10 times

### Idea behind the algorithm
The qualifying round will hopefully weed out the lower probability coins more often than not leaving half the flips to be used by the hopefully higher probability coins


## Implementation
The code is split into three files
- main.cpp: Implements the process of performing the algorithm on one run, performing 100 runs and it's data collection/production, and the terminal commands.
- Coin.cpp: Houses the Coin class and holds methods to perform the weighted coin flips and a sequence of them.
- Coin.h: The header file that declares the Coin class and all of its relevant functions and members.
