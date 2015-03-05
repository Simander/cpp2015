#include "player.hpp"
#include <string>
#include <iostream>

using namespace std;

Player::Player(){
	_numberOfCards = 0;
	_points = 0;
	_wallet = 1000;
}

//updates the players wallet according to result of previous round.
void Player::winlose(int i){
	_wallet+= i;
}

//returns the players points pr. current round
int Player::getSum(){
	return _points;
}

//resets the players points, and removes the cards from the players hand
void Player::resetStats(){
	_points = 0;
	_numberOfCards = 0;
	while(!hand.empty())
		hand.pop_back();
}

//returns the players _wallet
int Player::getWallet(){
	return _wallet;
}

//Puts a card in the players hand
bool Player::recieveCard(Card a){
	hand.push_back(a);
	_numberOfCards++;
	if(a.getValue() == 1){
		if(_points+11 <= 21)
			_points += 11;
		else
			_points += 1;
	}
	else if(a.getValue() < 10)
		_points+= a.getValue();
	else
		_points+=10;

	if(_points < 21) 
		return false;
	else
		return true;
}

//returns a card from players hand by index
Card Player::getCard(int i){
	return hand.at(i);
}

//returns the number of cards in the players hand.
int Player::getNumberOfCards(){
	return _numberOfCards;
}

//toString method, returns The cards in the players hand and how many points.
string Player::toString(){
	string s ="Your hand: ";
	for(int i = 0; i < _numberOfCards; i++){
		s+=hand.at(i).toString() + ", ";
	}
	s+= "\nYou have: " + to_string(getSum()) + " points";
	return s;
}
