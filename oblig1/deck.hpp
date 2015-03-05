#ifndef DECK_HPP
#define DECK_HPP


#include "card.hpp"
#include <vector>

using namespace std;

class Deck{
	
	vector<Card> deck;		//Vector for holding all cards in the deck
	int _counter;			//counter, counts how many cards have been dealt.
	
	public:
		Deck();							//Constructor
		Card getCard(int i);			//method that returns the card at index i in the deck
		void shuffle();					//metod for shuffling the deck
		void swapCards(int a, int b);	//subroutine of the shuffle method
		Card deal();					//method that deals a single card from the deck

};
#endif
