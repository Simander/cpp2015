#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card.hpp"
#include <vector>
#include <string>

class Player{
	private:
		int _numberOfCards;		//keeps track of how many cards is in the players hand.
		int _wallet;			//The player wallet
		int _points;			//How many points the player has pr. round
		std::vector<Card> hand;	//The players hand.

	public: 

		Player();					//Constructor
		bool recieveCard(Card a);	//method that puts a card in the players hand
		int getNumberOfCards();		//return number of cards in the players hand
		std::string toString();		//toString method returns cards and points.
		int getSum();				//returns the players points for the current round.
		void resetStats();			//resets the players score and removes cards from hand.
		void winlose(int i);		//updates wallet according to result of previous round.
		int getWallet();			//return wallet
		Card getCard(int i);		//return a card by index.
};

#endif
