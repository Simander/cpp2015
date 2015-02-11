#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card.hpp"
#include <vector>
#include <string>
//using namespace std;

class Player{
	int numberOfCards;
	int wallet;

	public: 
		int _points;
		bool stand;
		std::vector<Card> hand;
		Player();	
		bool recieveCard(Card a);
		int getNumberOfCards();
		std::string toString();
		int getSum();
		void resetStats();
		void winlose(int i);
		int getWallet();
		Card getCard(int i);
};
#endif
