#include "player.hpp"
#include <string>
#include <iostream>
using namespace std;
Player::Player(){
	_numberOfCards = 0;
	_points = 0;
	_wallet = 1000;
}
void Player::winlose(int i){
	_wallet+= i;
}

int Player::getSum(){
	return _points;
}
void Player::resetStats(){
	_points = 0;
	_numberOfCards = 0;
	while(!hand.empty())
		hand.pop_back();
}

int Player::getWallet(){
	return _wallet;
}

bool Player::recieveCard(Card a){
	hand.push_back(a);
	_numberOfCards++;
	if(a.getValue() < 10)
		_points+= a.getValue();
	else
		_points+=10;

	if(_points < 21) 
		return false;
	else
		return true;
}
Card Player::getCard(int i){
	return hand.at(i);
}

int Player::getNumberOfCards(){
	return _numberOfCards;
}

string Player::toString(){
	string s ="Your hand: ";
	for(int i = 0; i < _numberOfCards; i++){
		s+=hand.at(i).toString() + ", ";
	}
	s+= "\nYou have: " + to_string(getSum()) + " points";
	return s;
}
