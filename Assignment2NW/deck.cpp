// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "deck.h"
#include <iostream>

Deck::Deck()
{
	
}

bool Deck::isEmpty()
{
	if(numCards_==0)
		return 1;
	else
		return 0;
}

int Deck::getNumCards()
{
	return numCards_;
}

void Deck::displayCard(int i)
{
	std::cout << i << "th Card: " << deck_[i-1].print() << std::endl;
}

void Deck::printDeck()
{
	for(int i=0; i<numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
}

bool Deck::addCard(Card c)
{
	if(numCards_==0)
		return 1;
	else
		return 0;
}

void Deck::shuffle()
{
	srand(time(0));
	
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

bool Deck::mergeDecks(StandardDeck & k, bool b)
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

Card Deck::dealCard()
{
	if(numCards_!=0)
	{
		numCards_--;
		return(deck_[numCards_]);
	}
	else
		return Card(0,0);
}

std::string Deck::getTop()
{
	if(numCards_>0)
		return deck_[numCards_-1].getFace();
	else
		return "Ouch";
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

void NonStandardDeck::initializeDeck()
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
