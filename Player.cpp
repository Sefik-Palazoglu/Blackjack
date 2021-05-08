#include "Player.h"

#include <iostream>

Player::Player() : m_score{ 0 }, m_numofAces{ 0 } {}

void Player::drawCard(Deck &deck) {
  Card dealtCard{ deck.dealCard() };
  m_score += dealtCard.value();

  if (dealtCard.isAce()) m_numofAces++;

  if (isBust()) {
    while (isBust() && m_numofAces > 0) {
      m_score -= Card::aceValue - Card::reducedAceValue;
      m_numofAces--;
    }
  }

  m_hand.push_back(dealtCard);
}

int Player::score() const { return m_score; }

bool Player::isBust() { return m_score > maximumScore; }

bool Player::wantsHit() const {
  while (true) {
    std::cout << "(h) to hit, or (s) to stand: ";

    char ch{};
    std::cin >> ch;

    std::cin.ignore(32767, '\n');  // remove any extraneous input

    switch (ch) {
      case 'h':
        return true;
      case 's':
        return false;

      default:
        std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
  }
}

void Player::printSituation() {
  std::cout << "You have: " << score() << '\n';
  std::cout << "You have " << m_numofAces << " aces avaiable for reducing.\n";
  std::cout << "Your hand: ";
  for (const auto &card : m_hand) {
    card.print();
    std::cout << ' ';
  }
  std::cout << '\n';
}
