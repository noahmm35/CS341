// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "card.h"

#define DECK_SIZE 52

class StandardDeck : public Deck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		/// Default destructor.
		~StandardDeck();

		void initializeDeck();
};

#endif