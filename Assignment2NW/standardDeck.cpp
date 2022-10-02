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

bool StandardDeck::isEmpty()
{
	if(numCards_==0)
		return 1;
	else
		return 0;
}

int StandardDeck::getNumCards()
{
	return numCards_;
}

void StandardDeck::displayCard(int i)
{
	std::cout << i << "th Card: " << deck_[i-1].print() << std::endl;
}

void StandardDeck::printDeck()
{
	for(int i=0; i<numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
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

bool StandardDeck::addCard(Card c)
{
	if(numCards_<=52)
	{
		deck_[numCards_]=c;
		numCards_++;
		return 1;
	}
	else
	{
		return 0;
	}
}

void StandardDeck::shuffle()
{	
	srand((unsigned) time(0));
	
	for(int t=1; t<=5; t++)
	{
		for(int i=1; i<=numCards_; i++)
		{
			int r(0);
			Card swap = Card();
			r=(rand() % numCards_);
			
			swap=deck_[i-1];
			deck_[i-1]=deck_[r];
			deck_[r]=swap;
		}
	}
}

bool StandardDeck::mergeDecks(StandardDeck & k, bool b)
{
	int t=0,count=0;
	t=k.numCards_ + numCards_;
	Card* newDeck= new Card[t];
	
	for(int i=0; i<numCards_; i++)
	{
		newDeck[i]=deck_[i];
		count=i;
	}
	for(int j=0; j<k.numCards_; j++)
	{
		newDeck[count+j]=k.dealCard();
	}
	
	numCards_=t;
	deck_=newDeck;
	
	if(b)
	{
		k.shuffle();
	}
	
	return 1;
}

Card StandardDeck::dealCard()
{
	if(numCards_!=0)
	{
		numCards_--;
		return(deck_[numCards_]);
	}
	else
		return Card(0,0);
} 

std::string StandardDeck::getTop()
{
	if(numCards_>0)
		return deck_[numCards_-1].getFace();
	else
		return "Ouch";
}
