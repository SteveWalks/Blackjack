#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

class Blackjack
{
private:
	string userName;//hold users name
	string cardName;//holds strings representing the name of cards
	char userInput;//will be used to decide if game will be played
	char userChoice;//will hold users decision to hit or stay.
	char playAgain;//holds users decision to play a NEW game.
	
	map<int, int> mp;//this will be used to make sure our decks cards are always random.
	
	int aceValue;//holds the users choice to make the ace have a value of 1 or 11.
	int gameCounter;//counts games played
	int drawCounter;//counts draws
	int userWins, dealerWins;//holds amount of games won by user/dealer.
	int pokerChip;//this represents a pokerchip
	int userBet;//will holds the users bet.
	int userHand, dealerHand;//holds sum of both players hands.
	bool playing;//evaluates true while a game is being played.
	bool user_stay, dealer_stay;//if true user/dealer has decided to stay.
	
	vector<int> usersPurse;//holds users pokerChips
	vector<int> housePurse;//holds the casino's money. (if different difficulty level the house has more chips, and is therefore harder to beat)
	vector<string> userCards;//will hold users cards
	vector<string> dealerCards;//will hold computers cards
	vector<string> deck;//holds a shuffled deck of cards.

	enum cardValues;//will be used to assign each card its value for the game

public:
	Blackjack(string userName);//constructor that takes in a users name as its parameters

	int getCard(int);//takes in an int representing a random number between 1 and 52 and returns the card equivelant to that number in the deck.
	int shuffle();//generates a random card
	int generateRandom();//returns an int which is a random number between 1 and 52

	void displayDealerHand(vector<string>);//takes a vector of string and an int (which is the dealers hand) and displays the value of the hand and its sum, but keeping one card FACEDOWN so its value is unkown.
	void displayHand(vector<string>);
	void startGame();//begins game of war

	char getCard(int card, string &suitName);
				
};