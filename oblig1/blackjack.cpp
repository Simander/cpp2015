#include "player.hpp"
#include "dealer.hpp"
#include "card.hpp"
#include "deck.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game{
	Player player;
	Dealer dealer;
	
	
public: 
	Game();
	void firstRound();
	void newRound();
	void hit();
	void stand();
	int determineWinner();
	bool greaterThan21();
	void winOrLose(bool b);
	int returnWallet();
	bool p_stand = false;
	bool d_stand = false;
	int menuchoice = -1;
	int exitcode = -1;
	int bet = 0;
};

Game::Game(){
	//player = Player();
	//dealer = Dealer();
}

void Game::firstRound(){
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
}
bool Game::greaterThan21(){
	if(player.getSum() > 21)
		return true;
	if(dealer.getSum() > 21)
		return true;
	else return false;
}
int Game::returnWallet(){
	return player.getWallet();
}
int Game::determineWinner(){
	//1 for player; 0 for house
	if(dealer.getSum() > 21 && player.getSum() <= 21 )
		return 1;
	else if(player.getSum() == 21)
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

int main(){
	int roundNr = 1;
	
	Game game;
	int menuchoice = -1;
	cout << "Welcome to simple BlackJack\n"
		<"----------------------------------------------------------------------\n";
	while(game.returnWallet() > 0){
		
		srand(time(0)*roundNr);
		roundNr++;
	game.newRound();
	game.bet = 0;
	cout <<"You have: " << game.returnWallet() << " gold units.\n"
	<<"----------------------------------------------------------------------\n";
	cout << "How much would you like to bet? enter a number between 10 and 100:\n";
	cin >> game.bet;
	cout <<"----------------------------------------------------------------------\n";
	game.firstRound();
	
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

	
		if(game.determineWinner() == 1){
			cout << "\nYou win!\n"
			 <<"----------------------------------------------------------------------\n";
			game.winOrLose(true);
		}
		else{
			cout << "\nYou lose\n"
			<<"----------------------------------------------------------------------\n";
			game.winOrLose(false);
		}

	}
	cout << "You are broke, GAME OVER!"<< endl;
	return 0;
}
