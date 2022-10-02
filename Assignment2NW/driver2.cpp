// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include <iostream>
#include "card.h"
#include "standardDeck.h"

int main()
{	
	int w1=0,w2=0,p1Avg=0,p2Avg=0;
	
	for(int i=1; i<=50;i++)
	{
		int deal=0,s=0;
		StandardDeck bg;
		StandardDeck p1;
		StandardDeck p2;

		bg.initializeDeck();
		while(s<i)
		{
			bg.shuffle();
			s++;
		}
 	
		while(!bg.isEmpty())
		{
			if(deal%2==0)
			{
				p1.addCard(bg.dealCard());
			}
			else
			{
				p2.addCard(bg.dealCard());
			}
		
			deal++;
		}
		
		bg.addCard(p1.dealCard());
	
		while(!p1.isEmpty() && !p2.isEmpty())
		{
			if(bg.getTop()==p2.getTop())
			{
				while(!bg.isEmpty())
				{
					p2.addCard(bg.dealCard());
				}
				bg.addCard(p2.dealCard());
			}
			else
			{
				bg.addCard(p2.dealCard());
			}
		
			if(bg.getTop()==p1.getTop())
			{
				while(!bg.isEmpty())
				{
					p1.addCard(bg.dealCard());
				}
				bg.addCard(p1.dealCard());
			}
			else
			{
				bg.addCard(p1.dealCard());
			}
		}
		
		if (p1.isEmpty())
		{
			w2++;
			p2Avg += p2.getNumCards();
		}
		else
		{
			w1++;
			p1Avg += p1.getNumCards();
		}
	}

	p1Avg=p1Avg/w1;
	p2Avg=p2Avg/w2;
		
		if (w1>w2)
		{
			std::cout << "Player 1 was victorious over Player 2 with " << w1 << " victories!" << std::endl;
		}
		else if (w2>w1)
		{
			std::cout << "Player 2 was victorious over Player 1 with " << w2 << " victories!" << std::endl;
		}
		else if (w2=w1)
		{
			std::cout << "Player 1 and Player 2 TIED... well that's no fun" << std::endl;
		}
		else
		{
			std::cout << "oops" << std::endl;
		}
		
		std::cout << "Player 1 Average Score: " << p1Avg << std::endl;
		std::cout << "Player 2 Average Score: " << p2Avg << std::endl; 

	
	return 0;
}
