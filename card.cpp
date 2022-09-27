#include "card.h"
#include <iostream>

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

							
Card::Card()
{
	
}

Card::~Card()
{
		
}		

Card::Card(int x, int y) : suitVal_(0), faceVal_(0)
{
	suitVal_=y;
	faceVal_=x;
}					

std::string Card::getSuit()
{
	return SUIT[suitVal_];
}

std::string Card::getFace()
{
	return FACE[faceVal_];
}

std::string Card::print()
{
	std::string cardName("");
	cardName = cardName + FACE[faceVal_] + " of " + SUIT[suitVal_];
	return cardName;
}

void Card::initialize(int a, int b)
{
	suitVal_=b;
	faceVal_=a;
}