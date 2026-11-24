# Warpware_Coding_Challenge
This is the master branch of the repository I used to complete the Warpware Coding Challenge.

The repo contains several branches implementing different algorithms to solve the coin flip problem. Each branch's README has it's own basic explanation of the thought and procedure behind the algorithm. I would typically remove these branches now they aren't going to be in use but I figured it could be nice for you all at Warpware to see my different attempts and thought process. The other branches have not gone through the same cleanup/terminal control update as the master branch has. But they do all still run and produce the same formatted results.

# Comments on the Master Code

## How to Run
Compile the program with:

    g++  .\main.cpp .\Coin.cpp -o main

Then run the program with:

    .\main

You will then be presented with a welcome menu and a line detailing your options. The options were designed in order to make it easier to run multiple trials in a row within one instance of the program.

- Enter r in order to perform a trial of 100 runs and have the data displayed in the terminal.
- Enter q in order to terminate the program.



## Algorithm Description
This code implements a modified version an algorithm I dubbed "Hot Hand". It adds the "plus/minus" modification to the base algorithm that can be found in the "hot_hand" Branch.

- Build the coins and store them in a vector.

- Create an array of length 5 (one slot for each coin) initialized with 0s.

- Create a vector with integers {0,1,2,3,4} representing the indices of coins in the original vector.

- Pick a random int between 0 and the size of coins: that corresponds to a coin in the vector.
   - If it's heads: flip it again and increment that index of the +/- array.
   - If it's tails:
      - If the index has a +/- <= x, remove it from the vector of coins.
      - If the index has a +/- >= y, keep the same coin.
      - If the +/- is between x and y, choose a different randomly selected coin (forced to be different from the one just flipped, but can eventually return to the current coin).
          - Through some testing optimal values were found to be x := -4 and y:= 1.

### Idea behind the algorithm
Occam's Razor: When faced with competing hypotheses, the one with the fewest assumptions is usually the best.
The original Hot Hand algorithm surprisingly (or unsurprisingly if you're a believer in Occam) performed better than the other algorithms I implemented. The thought behind it being that naturally higher probability coins are more likely to succeed and stay as the hot hand while lower probability coins are more likely to fail and be kicked out. It also skips the mandatory multiple flips of low probability coins that the two qualifier algorithms entail.

The +/- addition (which, funnily enough, came to me while watching hockey with my partner) adds buffers to keep the volatility of Hot Hand in check. Because you don’t want to hold on to a bad coin for longer than you need or get rid of a good one because of a bad couple flips.

I have found that at very high number of trials (10,000 or 100,000) the heads/run settles around 12.7 with particularly lucky trials of 100 runs reaching upwards of 13.3. It is also a very simple algorithm in terms of time and space complexity so the 100,000 runs are actually doable.

## Implementation
The code is split into three files
- main.cpp: Implements the process of performing the algorithm on one run, performing 100 runs and it's data collection/production, and the terminal commands.
- Coin.cpp: Houses the Coin class and holds methods to perform the weighted coin flips and a sequence of them.
- Coin.h: The header file that declares the Coin class and all of its relevant functions and members.

## Requirements
C++20 compiler
Nothing else is required beyond the C++ standard library



