
#include "deck.h"

#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>


Deck::Deck(int deckNumber) {
  index_type card{ 0 };
  int a[] = { 1, 1, 2, 3, 4, 5 };

  auto suits{ static_cast<index_type>(Card::Suit::MAX_SUITS) };
  auto ranks{ static_cast<index_type>(Card::Rank::MAX_RANKS) };

  for (int i = 0; i < deckNumber; i++) {
    for (index_type suit{ 0 }; suit < suits; ++suit) {
      for (index_type rank{ 0 }; rank < ranks; ++rank) {
        // implicit card object
        m_deck.push_back(Card{ static_cast<Card::Rank>(rank),
                               static_cast<Card::Suit>(suit) });
      }
    }
  }
}

void Deck::print() const {
  for (const auto &card : m_deck) {
    card.print();
    std::cout << ' ';
  }

  std::cout << '\n';
}

void Deck::shuffle() {
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(
      std::time(nullptr)) };

  std::shuffle(m_deck.begin(), m_deck.end(), mt);

  m_cardIndex = 0;  // if we shuffle, we start from the top of the deck again
}

const Card &Deck::dealCard() {
  assert((m_cardIndex < m_deck.size()) &&
         "Deck::dealCard tried to deal a card that is out of the deck range.");

  return m_deck[m_cardIndex++];
}
