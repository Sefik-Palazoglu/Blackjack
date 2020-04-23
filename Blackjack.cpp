#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

// ...

int getDeckNumber()
{
	while (true) // Loop until user enters a valid input
	{
		std::cout << "Enter number of decks: ";
		int x;
		std::cin >> x;

		// Check for failed extraction
		if (std::cin.fail() || x <= 0) // has a previous extraction failed?
		{
			// yep, so let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(32767, '\n'); // and remove the bad input
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // remove any extraneous input

			// the user can't enter a meaningless double value, so we don't need to worry about validating that
			return x;
		}
	}
}

int main()
{
	Player player{};
	Player dealer{};

	Game game{ getDeckNumber(), player, dealer }; // start game with n number of decks

	game.playAndConcludeBlackjack();

	return 0;
}