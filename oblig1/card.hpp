#ifndef CARD_HPP
#define CARD_HPP

#include <string>


class Card{

	public:

		Card(int s, int v);
		int getValue();			//returns the cards value
		int getSuit();			//returns the cards suit
		std::string toString();		//returns a string with all the card data;
		//ostringstream oss;
	private:
		int _suit;	//0-diamonds, 1-hearts, 2-spades, 3-clubs
		int _value;	//ace 1, knight 10, queen 11, king 12 else, numbers 2-9
	};
	#endif
