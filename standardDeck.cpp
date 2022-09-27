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
	for(int i=0; i<52; i++)
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
		deck_[++numCards_]=c;
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
	
	for(int t=1; t<=3; t++)
	{
		for(int i=1; i<=numCards_; i++)
		{
			int r(0);
			Card swap = Card();
			r=(rand() % numCards_)+1;
			
			swap=deck_[i-1];
			deck_[i-1]=deck_[r];
			deck_[r]=swap;
		}
	}
}

bool StandardDeck::mergeDecks(StandardDeck & k, bool b)
{
	Card c[104];
	
	for(int i=0; i<=104; i=i+2)
	{
		c[i]=deck_[i];
		c[i+1]=deck_[i];
	}
	deck_=&c[0];
	
	if(b)
	{
		k.shuffle();
	}
	return 1;

}

/* void StandardDeck::dealCard()
{
	
} */