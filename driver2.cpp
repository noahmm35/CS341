#include <iostream>
#include "card.h"
#include "standardDeck.h"

int main()
{	
	StandardDeck bg;
	StandardDeck p1;
	StandardDeck p2;

	bg.initializeDeck();
	bg.shuffle();
	
	bg.displayCard(51);
	
	/* while(!bg.isEmpty())
	{
		int i=0;
		
		if(i%2==0)
		{
			p1.addCard(bg.dealCard());
		}
		else
		{
			p2.addCard(bg.dealCard());
		}
	}
	
	std::cout << "Player 1 Deck: " << std::endl;
	p1.printDeck();
	std::cout << "Player 2 Deck: " << std::endl;
	p2.printDeck();
	
	std::cout << "Bg Cards: " << bg.getNumCards() << std::endl;
	std::cout << "P1 Cards: " << p1.getNumCards() << std::endl;
	std::cout << "P2 Cards: " << p2.getNumCards() << std::endl;*/
	
	return 0;
}
