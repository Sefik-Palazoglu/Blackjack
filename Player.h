
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Deck.h"

class Player
{
public:
	static constexpr int maximumScore{ 21 };
	static constexpr int dealerMinScore{ 17 }; // 

private:
	int m_score{};
	int m_numofAces{};
	std::vector<Card> m_hand{};
	
public:
	Player();

	void drawCard(Deck& deck);

	int score() const;

	bool isBust();

	bool wantsHit() const;

	void printSituation();
};

#endif // !PLAYER_H

