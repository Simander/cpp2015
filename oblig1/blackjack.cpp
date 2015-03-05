#include "player.hpp"
#include "dealer.hpp"
#include "card.hpp"
#include "deck.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game{
	
	Player player; 	//The player
	Dealer dealer;	//The dealer
	
	
	public: 
		Game();	//Constructor
	
		void deal();	//defines action for the first round of every game.
		void newRound();	//defines action for every other round of the game.
		void hit();			//defines the action 
		void stand();
		int determineWinner();	//determines the winner based on result of round.
		bool greaterThan21();	
		void winOrLose(bool b);
		int returnWallet();
		void placeBet();
		bool isPUSH();
		bool isBUST();
		bool p_stand = false;	//boolean is true if player do stand
		bool d_stand = false;	//boolean is true if dealer does stand.
		int menuchoice = -1;	//variable for storing menu choices.
		int exitcode = -1;
		int bet = 0;			//how much the player has bet
};

Game::Game(){
}

void Game::placeBet(){
	//outputs how much money the player has to bet from
	cout <<"You have: " << returnWallet() << " gold units.\n"
		 <<"----------------------------------------------------------------------\n"
		 << "How much would you like to bet? enter a number between 10 and 100:\n";
	
	cin >> bet;	//places a bet from keyboard input.

	//if bet is too low or too high Dealer asks the player to place a new bet.	
	while(bet < 10 || bet > 100 || bet > player.getWallet()){
		if(bet > player.getWallet())
			cout << "Bet exeeds your wallet, please place a new bet:\n";
		else if(bet < 10 || bet > 100)
			cout << "Invalid bet, bets must be between 10 and 100, \nplease place a new bet:\n";
		cin >> bet;
		
	}
	cout <<"----------------------------------------------------------------------\n";	
}

//Deals two cards to start a round, for the rest of the game it autodeals.
void Game::deal(){
	dealer.shuffle();
	p_stand = player.recieveCard(dealer.deal());
	p_stand = player.recieveCard(dealer.deal());
	cout << "You recieved a |" << player.getCard(0).toString() << "| and a |" 
		<< player.getCard(1).toString() << "|\nYou now have: " << player.getSum() << "points\n";// << player.getSum() << endl;
	d_stand = dealer.recieveCard();
	d_stand = dealer.recieveCard();
	cout << "Dealer has: " << dealer.getSum() << " points" << endl;
}

void Game::hit(){
	
	p_stand = player.recieveCard(dealer.deal());
	cout << "You recieved a |" << player.getCard(player.getNumberOfCards()-1).toString()
		 << "|\nYou now have: " << player.getSum() << "points\n";
	d_stand = dealer.recieveCard();
	cout << "Dealer has: " << dealer.getSum() << " points " << endl;
	if(d_stand && !p_stand)
		exitcode = 1;
	else if(p_stand && d_stand)
		exitcode = 1;
}
void Game::winOrLose(bool b){
	if(b == true)
		if(player.getSum()==21)
			player.winlose(bet*2);
		else 
			player.winlose(bet);
	else
		player.winlose(bet*(-1));
}
void Game::stand(){
	while(!d_stand){
		cout << "\nYou have: " << player.getSum() << " points\n";
		d_stand = dealer.recieveCard();
		cout << "Dealer has: " << dealer.getSum() << " points\n";
		if(dealer.getSum() >= 18)	//dealer stopper når han er høyere eller lik 18 poeng.
		{
			d_stand = true;
			break;
		}
	}

}
void Game::newRound(){
	player.resetStats();
	dealer.resetStats();
	bet = 0;
}
//true if PUSH, only to be run when round is over.
bool Game::isPUSH(){
	if(player.getSum() == dealer.getSum() && player.getSum() < 21)
		return true;
	else
		return false;
}
bool Game::isBUST(){
	if(player.getSum() > 21)
		return true;
	else
		return false;
}

bool Game::greaterThan21(){
	if(player.getSum() >= 21)
		return true;
	if(dealer.getSum() >= 21)
		return true;
	return false;
}
int Game::returnWallet(){
	return player.getWallet();
}
int Game::determineWinner(){
	/*	1 for regular win, 2 for blackjack(player)
	 	0 for regular win, 3 for blackjack (house) */
	if(player.getSum() == 21)
		return 2;
	else if(dealer.getSum() == 21)
		return 3;
	else if(dealer.getSum() > 21 && player.getSum() < 21 )
		return 1;
	else if(player.getSum() > 21)
		return 0;
	else if(dealer.getSum() > 21)
		return 1;
	else if(player.getSum() > dealer.getSum() && d_stand == true)
		return 1;
	else
		return 0;
}
//MAIN MENU AKA GAMELOOP
int main(){
	int roundNr = 1;
	
	Game game;
	
	int menuchoice = -1;

	//intro message
	cout <<"----------------------------------------------------------------------\n" 
		 << "Welcome to simple BlackJack\n"
		 <<"----------------------------------------------------------------------\n";
	
	//While the player still have money the game goes on unless player quits.
	while(game.returnWallet() > 0){
		
		//srand(time(0)*roundNr);
		roundNr++;
		
		game.newRound();	//Sends a signal to reset the game for a new round.

		game.placeBet();	//Places a bet;
	
		game.deal();	//deals cards
	
	while(menuchoice != 3){
		cout <<"----------------------------------------------------------------------\n";
		if(game.greaterThan21() == true)
			break;
		cout << "\n1. Hit\n2. Stand\n3. Quit\n";
		cin >> menuchoice;
		cout <<"----------------------------------------------------------------------\n";
		if(menuchoice == 1)
			game.hit();
		else if(menuchoice == 3)
			return 0;
		else 
			break;		

	}
	if(menuchoice == 2)
		game.stand();

	
		if(game.isPUSH()){	//Checks for PUSH
			cout << "\nPUSH!\n"
			<<"----------------------------------------------------------------------\n";	
		}
		else if(game.isBUST()){	//Checks for BUST
			cout << "\nBUST! You lose!\n"
			<<"----------------------------------------------------------------------\n";
			game.winOrLose(false);
		}
		else if(game.determineWinner() == 1){	//regular win
			cout << "\nYou win!\n"
			<<"----------------------------------------------------------------------\n";
			game.winOrLose(true);
		}
		else if(game.determineWinner() == 2){	//player blackjack
			cout << "\nBLACKJACK! winnings is doubled!\n"
			 <<"----------------------------------------------------------------------\n";
			game.winOrLose(true);
		}
		else if(game.determineWinner() == 3){	//dealer blackjack
			cout << "\nDealer got BLACKJACK, you loose!\n"
			 <<"----------------------------------------------------------------------\n";
			game.winOrLose(false);
		}
		else{
			cout << "Dealer won! You lose!\n"	//regular loss
			<<"----------------------------------------------------------------------\n";
			game.winOrLose(false);
		}

	}
	cout << "You are broke, GAME OVER!"<< endl;
	return 0;
}
