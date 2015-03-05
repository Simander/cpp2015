#include "deck.hpp"
#include "card.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;


//Constructor
Deck::Deck(){			//works c++11
	
	_counter = 0;
		for(int x = 0; x < 48; x++){
		for(int i = 0; i < 4; i++){
			for(int j = 1; j < 14; j++){
				deck.push_back(Card(i,j));
				x++;
			}
		}
	}	
}

//returns a card from the deck by index
Card Deck::getCard(int i){
	return deck.at(i);
}

//Method for shuffling the deck
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

//sub routinge of the shuffle method, swaps two cards by their index.
void Deck::swapCards(int a, int b){		//works c++11
	Card tmp = deck.at(a);
	deck.at(a) = deck.at(b);
	deck.at(b) = tmp;
}

//Method that deals a single card from the deck and increments counter.
Card Deck::deal(){
	_counter++;
	return deck.at(_counter-1);
}
