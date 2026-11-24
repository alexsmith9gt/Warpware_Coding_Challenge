# Warpware_Coding_Challenge
This is the hot_hand branch of the repository I used to complete the Warpware Coding Challenge.

# Comments on the Code

## How to Run
Compile the program with:

    g++  .\main.cpp .\Coin.cpp -o main

Then run the program with:

    .\main

## Algorithm Description
This code implements the original version an algorithm I dubbed "Hot Hand".

- Build the coins and store them in a vector.

- Pick a random int between 0 and the size of coins: that corresponds to a coin in the vector.
   - If it's heads:
     - Flip it again and increment that index of the +/- array.
   - If it's tails:
      - If the +/- is between x and y, choose a different randomly selected coin (forced to be different from the one just flipped, but can eventually return to the current coin).

### Idea behind the algorithm
Occam's Razor: When faced with competing hypotheses, the one with the fewest assumptions is usually the best.
The original Hot Hand algorithm surprisingly (or unsurprisingly if you're a believer in Occam) performed better than the other algorithms I implemented. The thought behind it being that naturally higher probability coins are more likely to succeed and stay as the hot hand while lower probability coins are more likely to fail and be kicked out. It also skips the mandatory multiple flips of low probability coins that the two qualifier algorithms entail.


## Implementation
The code is split into three files
- main.cpp: Implements the process of performing the algorithm on one run, performing 100 runs and it's data collection/production, and the terminal commands.
- Coin.cpp: Houses the Coin class and holds methods to perform the weighted coin flips and a sequence of them.
- Coin.h: The header file that declares the Coin class and all of its relevant functions and members.
