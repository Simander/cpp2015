#ifndef DECK_HPP
#define DECK_HPP


#include "card.hpp"
#include <vector>

using namespace std;

class Deck{
	vector<Card> deck;
	int counter;
	public:
		Deck();
		//deck.reserve(52);
		Card getCard(int i);			//method that returns the card at index i in the deck
		void shuffle();					//method for shuffling the deck
		void swapCards(int a, int b);	//part of shuffle
		Card deal();

};
#endif
