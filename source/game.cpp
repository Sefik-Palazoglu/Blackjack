
#include "game.h"

#include <iostream>

Game::Game(int deckNumber, Player &player, Player &dealer)
    : m_deckNumber{ deckNumber },
      m_deck{ Deck{ deckNumber } },
      m_player{ player },
      m_dealer{ dealer } {}

void Game::playAndConcludeBlackjack() {
  Game::Result result{ playBlackjack() };

  switch (result) {
    case Game::Result::PLAYER_WIN:
      std::cout << "You win!\n";
      break;
    case Game::Result::DEALER_BUST:
      std::cout << "The dealer went bust.\nYou win!\n";
      break;
    case Game::Result::DEALER_WIN:
      std::cout << "You lose!\n";
      break;
    case Game::Result::PLAYER_BUST:
      std::cout << "You went bust.\nYou lose!\n";
      break;
    case Game::Result::TIE:
      std::cout << "It is a tie!\n";
    default:
      break;
  }

  std::cout << "The player's final score: " << m_player.score() << '\n';
  std::cout << "The dealer's final score: " << m_dealer.score() << '\n';
}

Game::Result Game::playBlackjack() {
  m_deck.shuffle();

  m_dealer.drawCard(m_deck);

  std::cout << "The dealer is showing: " << m_dealer.score() << '\n';

  m_player.drawCard(m_deck);
  m_player.drawCard(m_deck);

  if (playerTurn()) {
    return Game::Result::PLAYER_BUST;
  }

  if (dealerTurn()) {
    return Game::Result::DEALER_BUST;
  }

  if (m_player.score() < m_dealer.score())
    return Game::Result::DEALER_WIN;
  else if (m_dealer.score() < m_player.score())
    return Game::Result::PLAYER_WIN;
  else
    return Game::Result::TIE;
}

bool Game::playerTurn() {
  while (true) {
    m_player.printSituation();

    if (m_player.isBust()) {
      return true;  // The player went bust
    } else {
      if (m_player.wantsHit()) {
        m_player.drawCard(m_deck);
      } else {
        // The player didn't go bust.
        return false;
      }
    }
  }
}

bool Game::dealerTurn() {
  while (m_dealer.score() < Player::dealerMinScore) {
    m_dealer.drawCard(m_deck);
  }

  // return true if dealer went bust; otherwise, false.
  return m_dealer.isBust();
}
