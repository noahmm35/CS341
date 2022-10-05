// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "standardDeck.h"
#include <iostream>

StandardDeck::StandardDeck()
{
	numCards_=0;
	deck_ = new Card[52];
}

StandardDeck::~StandardDeck()
{
	delete [] deck_;
}

void StandardDeck::initializeDeck()
{
 	int a=0;
	Card cards[52];

	for(int i=1; i<=4; i++)
	{
		for(int j=1; j<=13; j++)
		{
			cards[a].initialize(j,i);
			deck_[a]=cards[a];
			a++;
		}
	} 
	numCards_=a;
}
