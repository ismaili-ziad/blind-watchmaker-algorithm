# Simulation of Natural Selection
Proposed C++ implementation of Natural Selection as per Richard Dawkins in 'The Blind Watchmaker'

In Richard Dawkins' famous book 'The Blind Watchmaker', he explains a simple yet powerful algorithmic way to illustrate evolution by natural selection.
The goal is to start from a string of random characters, and mutate it until a goal sentence is reached.

In my proposed implementation, the algorithm works in the following way:

* Let N be the number of characters in our goal sentence/string G.
* A random string S of N characters consisting of uppercase Latin letters is generated.
* While S is not equal to G:
  * Create X copies of S, but in each copy, at most four randomly selected letters are changed (mutation).
  * Select the copy that has the most matching letters with G.
  * Let S be the copy previously selected.
* Display S.

The programme also counts the number of generations required for mutations to reach their goal.

I aim to improve this algorithm by prompting the user the phrase they want to reach.
