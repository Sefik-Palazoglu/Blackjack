#ifndef DECK_H
#define DECK_H

#include <vector>

#include "Card.h"


class Deck {
 public:
  static constexpr int singleDeckSize{ 52 };
  using array_type = std::vector<Card>;
  using index_type = array_type::size_type;

 private:
  array_type m_deck{};
  index_type m_cardIndex{ 0 };

 public:
  Deck(int deckNumber = 1);

  void print() const;

  void shuffle();

  const Card& dealCard();
};
#endif  // !DECK_H
