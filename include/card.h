#ifndef CARD_H
#define CARD_H

class Card {
 public:
  enum class Suit {
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,

    MAX_SUITS
  };

  enum class Rank {
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,

    MAX_RANKS
  };

  static constexpr int aceValue{ 11 };
  static constexpr int reducedAceValue{ 1 };

 private:
  Rank m_rank{};
  Suit m_suit{};

 public:
  Card() = default;
  Card(const Rank& rank, const Suit& suit);

  void print() const;
  int value() const;
  bool isAce() const;
};

#endif  // !CARD_H
