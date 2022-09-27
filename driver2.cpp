#include <iostream>
#include "card.h"
#include "standardDeck.h"

int main()
{	
	StandardDeck dk;
	dk.initializeDeck();
	
	dk.mergeDecks(dk,1);
	
	std::cout << "Is the Deck Empty? " << dk.isEmpty() << std::endl;
	std::cout << "Number of Cards: " << dk.getNumCards() << std::endl;
	
	dk.displayCard(1);
	dk.displayCard(52);
	dk.displayCard(100);
	
	dk.shuffle();
	
	dk.displayCard(1);
	dk.displayCard(52);
	dk.displayCard(100);	
	
	return 0;
}