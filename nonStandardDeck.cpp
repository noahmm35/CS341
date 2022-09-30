// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "nonStandardDeck.h"
#include <iostream>
#include <fstream>

NonStandardDeck()
{
	
}

NonStandardDeck(int x)
{
	deck_ = new Card[x];
	numCards_=0;
}

~NonStandardDeck()
{
	
}

initializeDeck()
{
	int size=0, fillFace=0, fillSuit=0;
	std::ifstream input("deck.txt");
	
	if(input.is_open())
	{
		input >> size;
		
		deck_ = new Card[size];
		
		for(int i=0; i<size; i++)
		{
			input >> fillSuit >> fillFace;
			Card hold= Card(fillFace, fillSuit);
			deck_[i]=hold;
		}
		numCards_=size-1;
	}
}