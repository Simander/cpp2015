#include "dealer.hpp"
#include "card.hpp"
#include "deck.hpp"


using namespace std;

Dealer::Dealer(){
	 numberOfCards = 0;
	 _points = 0;
	 
}


void Dealer::shuffle(){
	deck.shuffle();
}

Card Dealer::deal(){
	return deck.deal();
}

bool Dealer::recieveCard(){
	if(_points < 18){
	
		hand.push_back(deck.deal());
		numberOfCards++;
		if(hand.at(numberOfCards-1).getValue() < 10)
			_points+= hand.at(numberOfCards-1).getValue();
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
	numberOfCards = 0;
	deck.shuffle();
	//deck.nullCounter();
	while(!hand.empty())
		hand.pop_back();
	
}
int Dealer::getNumberOfCards(){
	return numberOfCards;
}

