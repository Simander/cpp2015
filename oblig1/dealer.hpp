#ifndef DEALER_HPP
#define DEALER_HPP

#include "card.hpp"
#include "deck.hpp"
#include <vector>

class Dealer{

	private: 
		Deck deck;			//the deck of cards from which the dealer deals.
		vector<Card> hand;	//The dealers hand, holds his cards pr. round.
		int _numberOfCards;	//numberOfCards in hand
		int _points;		//counts points during a round
		
	public:
	

	Dealer();			//Constructor
	void shuffle();		//Method for shuffling the deck
	Card deal();		//Method for dealing a single card from the deck
	bool recieveCard();	//Method for recieving a card from the deck.
	int getSum();		//Method that returns the sum of points during a round.
	void resetStats();	//Method that resets the dealers stats, and shuffles the deck
	int getNumberOfCards();	//Method returns number of cards in the dealers hand.

};
#endif
