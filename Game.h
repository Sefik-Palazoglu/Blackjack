
#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

class Game {
 public:
  enum class Result { PLAYER_WIN, DEALER_BUST, DEALER_WIN, PLAYER_BUST, TIE };

 private:
  int m_deckNumber{};
  Deck m_deck{};
  Player m_player{};
  Player m_dealer{};

 public:
  Game(int deckNumber, Player& player, Player& dealer);

  void playAndConcludeBlackjack();

  Result playBlackjack();

  bool playerTurn();

  bool dealerTurn();
};

#endif  // !GAME_H
