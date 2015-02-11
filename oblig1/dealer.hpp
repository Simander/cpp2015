#ifndef DEALER_HPP
#define DEALER_HPP

#include "card.hpp"
#include "deck.hpp"
#include <vector>
//#include<string>
class Dealer{

	private: Deck deck;

	vector<Card> hand;
	
	public:
	int numberOfCards;
	int _points;
	bool stand;

	Dealer();
	void shuffle();
	Card deal();
	bool recieveCard();
	int getSum();
	void resetStats();
	int getNumberOfCards();

};
#endif
