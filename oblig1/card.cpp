
#include "card.hpp"
#include <string>

using namespace std;

	//Constructor
	Card::Card(int s, int v){
		_suit = s;
		_value = v;
	}
	
	//returns value of card
	int Card::getValue(){
		return _value;
	}

	//returns suit of card
	int Card::getSuit(){
		return _suit;
	}
	
	//toString card
	string Card::toString(){
		string s;
		switch(_value){
			case 1:
				s+="ace of ";
				break;
			case 11:
				s+="knight of ";
				break;
			case 12:
				s+="queen of ";
				break;
			case 13:
				s+="king of ";
				break;
			default:
				
				s+= to_string(_value) +" of ";
				break;
		}
		switch(_suit){
			case 0:
				s+= /*"diamond";*/"♦";
				break;
			case 1:
				s+= /*"hearts";*/"♥";
				break;
			case 2:
				s+=/*"spades";*/"♠";
				break;
			case 3:
				s+= /*"clubs";*/"♣";
				break;
		}
		return s;
	}
