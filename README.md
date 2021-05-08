# Blackjack
Blackjack is a little game that runs on command line. You can play blackjack with your computer who plays as a dealer against you.

I came across the idea when I was studying C++ [learncpp.com](https://www.learncpp.com/). The folks out there created this as a quiz which you are supposed to implement after completing their arrays chapter. They assign you the same task but expect you to do it in OOP after the basic OOP chapter. You can find the questions here:
- [initial quiz](https://www.learncpp.com/cpp-tutorial/chapter-9-comprehensive-quiz/)
- [OOP version](https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz/)

I shamelessly copy-pasted some of their code, but I am improving, refactoring, commenting it and adding additional features in here.

# How To Play
If you are on Linux and have g++, make, and ar utilities installed on your system, it is very easy to start playing!
1. Clone the repo on your machine by typing `git clone <link>` in your CLI.
2. Navigate in the repo and type `make` in your CLI.
3. If you didn't receive any errors (hopefully) type `./blackjack.exe` and start playing!

### Rules
- If the player is dealt an Ace and a ten-value card (called a "blackjack" or "natural"), and the dealer does not, the player wins and usually receives a bonus. (Not implemented yet)
- If the player exceeds a sum of 21 ("busts"), the player loses, even if the dealer also exceeds 21.
- If the dealer exceeds 21 ("busts") and the player does not, the player wins.
- If the player attains a final sum higher than the dealer and does not bust, the player wins.
- If both dealer and player receive a blackjack or any other hands with the same sum, this will be called a "tie" and no one wins.

You can checkout [here](https://en.wikipedia.org/wiki/Blackjack) for additional information.

### Gameflow
- Dealer asks you how many decks should be shuffled together.
  - Enter the number 2 to play with 104 cards or 3 to play with 156 cards.
- After that, in every turn you have two options: (h)it or (s)tand.
  - hit to draw another card and risk going bust!
  - stand if you are comfortable with your score.
