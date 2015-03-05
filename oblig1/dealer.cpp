#include "dealer.hpp"
#include "card.hpp"
#include "deck.hpp"


using namespace std;

//Constructor
Dealer::Dealer(){
	 _numberOfCards = 0;
	 _points = 0;
	 
}

//Method for shuffling the deck
void Dealer::shuffle(){
	deck.shuffle();
}
//Method for dealing a single card from the deck.
Card Dealer::deal(){
	return deck.deal();
}
//method for recieving a card returns false if STAND or BLACKJACK
bool Dealer::recieveCard(){
	if(_points < 18){
	
		hand.push_back(deck.deal());
		_numberOfCards++;
		if(hand.at(_numberOfCards-1).getValue() < 10)
			_points+= hand.at(_numberOfCards-1).getValue();
		else
			_points+=10;
	}
	if(_points > 18)
		return true;
	else if(_points <= 21)
		 return false;
	else
		return true;
	
}

int Dealer::getSum(){
	return _points;
}
void Dealer::resetStats(){
	_points = 0;
	_numberOfCards = 0;
	deck.shuffle();
	//Empties hand
	while(!hand.empty())
		hand.pop_back();
	
}
int Dealer::getNumberOfCards(){
	return _numberOfCards;
}

