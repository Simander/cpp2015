#include "deck.hpp"
#include "card.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

Deck::Deck(){			//works c++11
	
	counter = 0;
	//deck.reserve(52);
	for(int x = 0; x < 48; x++){
		for(int i = 0; i < 4; i++){
			for(int j = 1; j < 14; j++){
				deck.push_back(Card(i,j));
				x++;
			}
		}
	}	
}
Card Deck::getCard(int i){
	return deck.at(i);
}

void Deck::shuffle(){	//works c++11
	srand(time(NULL));
	counter = 0;
	int rand1;
	int rand2;
	//splits the deck in half, and swaps random cards from each side of the deck
	for(int i = 0; i < 52; i++){
		rand1 = rand()%(52/2); 
		rand2 =  rand()%(52/2)+(52/2);
		swapCards(rand1, rand2);
	}
}

void Deck::swapCards(int a, int b){		//works c++11
	Card tmp = deck.at(a);
	deck.at(a) = deck.at(b);
	deck.at(b) = tmp;
}
Card Deck::deal(){
	counter++;
	return deck.at(counter-1);
}