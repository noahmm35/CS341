// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "card.h"

class NonStandardDeck: public Deck
{
	public:
		NonStandardDeck();
	
		NonStandardDeck(int);
	
		~NonStandardDeck();
	
		void initializeDeck();
};