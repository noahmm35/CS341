// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "card.h"
#include "standardDeck.h"
#include "nonStandardDeck.h"
#include <iostream>

class Deck
{
	protected:
		Card * deck_;
		int numCards_;
		
	public:
		Deck();
		virtual ~Deck() {}
		bool isEmpty();
		int getNumCards();
		void displayCard(int i);
		void printDeck();
		bool addCard(Card c);
		void shuffle();
		bool mergeDecks(StandardDeck &, bool);
		Card dealCard();
		std::string getTop();
		
		virtual void initializeDeck() = 0;
};

class StandardDeck: public Deck
{
	public:
		void initializeDeck();
};

class NonStandardDeck: public Deck
{
	public:
		void initializeDeck();
};