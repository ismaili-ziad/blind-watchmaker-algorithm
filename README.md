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

# Example

Here was the resulting sequence for the string "THANK YOU VERY MUCH FOR YOUR ATTENTION PLEASE EXIT THE BUILDING" at X = 1,000,000 on my machine:

```
1: O QN KDJQCILHGZFZIVJSYOSWQGFIXUSCJGNRBZMCYCMPUVQLKFXTGDHCVQWELX
2: O QN KDJUCILHGZFZCVJSYOSWQGFIXUSCJGNRBZMLYCMPUVQLKFXTGDHCVQWCLX
3: O AN KDJUCILHGZFZCHJSYOSWQGFIAUSCJGNRBZMLYCSPUVQLKFXTGDHCVQWCLX
4: O AN KYJUCILHGZFZCHGSYOSWQGFIAUSCJTNRBZMLYCSPUVQIKFXTGDHCVQWCLX
5: O AN KYJU VLHYZFZCHGSYOSWQGFIAUSCJTNRBZMLYCSPUVQIKHXTGDHCVQWCLX
6: O AN KYJU VLHYZMZCHGSYOSWQGFIAUSCJTNRBZMLYCSPUVQITHXTGDHUVQWILX
7: O AN KYJU VLHYZMUCHGSOOBWQGFIAUSCJTNRBZMLYCSPUVQITHXTGDHUVLWILX
8: O AN KYJU VLHYZMUCH SOOBWQGFIAUSCJTNRBZMLYCSPUVQITHXTGDHUVLDING
9: OHAN KYJU VEHYZMUCH SOOBWQGFIAUSEJTNRBZMLYCSPUVQITHXHGDHUVLDING
10: OHAN KYJU VEHYZMUCH SOO WQGRIAUSEJTNRBZMLYCSPUVQITHXHEXHUVLDING
11: OHAN KYJU VEHYZMUCH SOO YQGRIAUSENTNRBZMLYCSE VQITHXHEXHUVLDING
12: OHAN  YOU VEHYZMUCH SOO YQGRIAUSENTNRB MLYCSE VQITHTHEXHUVLDING
13: OHAN  YOU VEHYZMUCH FOO YQUR ATSENTNRB MLYCSE VQITHTHEXHUVLDING
14: THAN  YOU VEHYZMUCH FOR YQUR ATSENTIOB MLYCSE VQITHTHEXHUVLDING
15: THANK YOU VEHYZMUCH FOR YQUR ATSENTION PLYCSE VQITHTHEXHUVLDING
16: THANK YOU VERYZMUCH FOR YQUR ATSENTION PLBASE VXITHTHEXHUVLDING
17: THANK YOU VERYZMUCH FOR YIUR ATSENTION PLBASE EXIT THE HUVLDING
18: THANK YOU VERYZMUCH FOR YOUR ATSENTION PLBASE EXIT THE BUILDING
19: THANK YOU VERY MUCH FOR YOUR ATTENTION PLEASE EXIT THE BUILDING
```
