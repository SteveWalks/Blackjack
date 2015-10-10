#include "Blackjack.h"

Blackjack::Blackjack(string name)
{
	userName = name;
}//end constructor


int Blackjack::getCard(int card)
{
	int m = card / 13;
	int n = card % 13;

	if (n == 0)
	{
		m--;
		n = 13;
	}//end if

	return n;
}

int Blackjack::shuffle()
{
	int n = rand() % 52 + 1;
	return n;
}//end method



void Blackjack::displayDealerHand(vector<string> hand)
{

	for (int i = 0; i < hand.size(); i++)
	{
		//if dealers second card comes up, don't show it to the user.
		if (i == 1)
		{
			cout << "-FACEDOWN-" << ", ";
		}
		else//show the user the dealers other cards
		{
			cout << hand[i] << ", ";
		}//end if else

	}//end for

	cout << endl;

}//end function


void Blackjack::displayHand(vector<string> hand)
{
	for (int i = 0; i < hand.size(); i++)
	{
		cout << hand[i] << ", ";
	}//end for

	cout << endl;
}//end function


int getAceValue(int &userHand)
{
	//flush buffer
	cin.clear();
	fflush(stdin);

	int aceValue = 0;//holds either a 1 or 11.
	cout << "YOU'VE BEEN DEALT AN ACE!\nYou can give an ACE a value of 1 or 11." << endl;

	while (aceValue != 1 && aceValue != 11)
	{
		cout << "What value will you give it, 1 or 11? ";
		cin >> aceValue;

		while (!cin)
		{
			cout << "I don't think you should be playing cards\nif you think that is a number,\nEnter a 1 or 11. ";
			cin.clear();
			cin.ignore();

			cin >> aceValue;
		}//end inner while

	}//end outer while

	//if the user gives ACE a value of 1
	if (aceValue == 1)
	{
		return userHand -= 10;//userHand has 10 taken 
	}
	else
	{
		return userHand;//Ace is set to 11 by default, we don't need to change anything.
	}//end if else

}//end method




void Blackjack::startGame()
{
	string cardName[] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "KING", "QUEEN", "ACE" };

	map<int, int> mp;
	map<string, int> card;
	deque<int> userPurse;//holds users pokerChips

	gameCounter = 0;//starts with 0
	playing = false;//playing is false by default until user decides to play
	pokerChip = 1000;//each poker chip = $1000.00
	userBet = 0;
	aceValue = 0;//this will hold the users choice to make the ACE have a face value of either 1 or 11.
	userInput = ' ';//this variable will be used to decide if the user decides to quit before starting program
	userChoice;//this variable will hold users decision to hit or stay.
	playAgain;
	user_stay, dealer_stay;//will evaluate to true if the user or dealer decide to STAY(not take anymore cards)
	userWins = 0;
	dealerWins = 0;
	drawCounter = 0;//holds number of draws occured.

	/*this for loop will iterate through our cards
	and assign each card its appropriate value*/
	for (int i = 0; i < 12; ++i)
	{
		//we make cards 10 to K = 10
		if (i > 8)
		{
			card[cardName[i]] = 10;
		}
		else
		{
			card[cardName[i]] = i + 2;
		}//end if else

	}//end for 

	//The ACE will = 11
	card[cardName[12]] = 11;



	//Output rules and make sure the user wants to play.
	cout << "Alright " << userName << ", this is Blackjack, best of 5 hands wins, you sittin' in?" << endl;

	//data validation
	while (userInput != 'Q' && userInput != 'Y')
	{
		cout << "\nEnter 'Q' to leave,\nor 'Y' to sit down and play BlackJack: ";
		cin >> userInput;
		userInput = toupper(userInput);//convert to uppercase for easier comparison

	}//end while



	//if user enters Y, playing evaluates to true and we give the user 10 Poker Chips
	if (userInput == 'Y')
	{
		playing = true;

		cout << "\nHere are 10 Poker Chips to start you off, 1 Chip = $1000.00"
			"\nyou must bet at least one chip to play.\nBet all 10 if you're feelin lucky.\n" << endl;
		//give player 10 PokerChips
		for (int i = 0; i < 10; ++i)
		{
			userPurse.push_back(pokerChip);
		}//end for

	}
	else//if they press Q the program ends.
	{
		cout << "Very well, good day." << endl;//quit game.
	}//end if else

	

	//Game begins inside this while loop
	while (playing == true)
	{	
		//set variables to appropriate values
		gameCounter = 0;
		userWins = 0;
		dealerWins = 0;
		userBet = 0;

		//flush buffer incase user entered more than one character
		cin.clear();
		fflush(stdin);


		cout <<  userName << "'s Purse: $" << (userPurse.size() * pokerChip) << endl;
		cout << "Alright " << userName << ", Place your bet: ";
		//validate input, make sure users bet is at least 1 and not > their purse.	
		while (userBet > userPurse.size() || userBet < 1)
		{
			userBet = 0;
			cin >> userBet;

			//while input is not an integer, we clear buffer and ask for new input
			while (!cin)
			{
				cout << "That is not a number,\nenter the number of chips you want to bet: ";
				cin.clear();//empty buffer
				cin.ignore();//ignore what was entered.
				cin >> userBet;
			}//end inner while	

			//output the problem with their input so the user knows
			if (userBet < 1)
			{
				cout << "You need to bet at least one chip cheap-o,\nenter the number of chips you want to bet:  ";
			}
			else if (userBet > userPurse.size())
			{
				cout << "Hah, you don't have that many chips " << userName << ",\nenter the number of chips you want to bet: ";
			}//end if else

		}//end middle while

		//remove PokerChips they bet from purse
		for (int i = 0; i < userBet; ++i)
		{
			userPurse.pop_back();
		}//end for


		//OUTPUT TEST
		cout << "\n\n" << userName << "'s Purse: $" << (userPurse.size() * pokerChip) << endl;
		cout << userName << "'s Bet: $" << (userBet * pokerChip) << endl;

		 
		srand(time(NULL));//new random number to use for shuffling.
	
		//create out
		vector<string> userCards;
		vector<string> dealerCards;
		vector<string> deck;
		map<int, int>mp;

		while (userWins < 3 && dealerWins < 3)
		{
			++gameCounter; //increment gameCounter
			//We clear the players hands and reshuffle the deck to start a new game.
			userCards.clear();
			dealerCards.clear();
			deck.clear();
			mp.clear();


			//output player bet, game #, and wins for each player
			cout << "===============GAME=STATS=================" << endl;
			cout << "GAME " << gameCounter << endl;
			cout << userName << "'s GAMES WON: " << userWins << "\nDEALER GAMES WON: " << dealerWins << "\n" << "DRAWS: " << drawCounter << endl;
			cout << "================GAME=" << gameCounter << "=====================" << endl;
			int randCard = shuffle();
			int usedCard = 1;//

			//shuffle deck, MAKE METHOD AFTER
			for (int i = 0; i < 52; i++)
			{
				while (mp[randCard] == usedCard)//while a card has already been placed in the deck, we search for another card.
				{
					randCard = shuffle();//so we must generate a new card 
				}//end while

				mp[randCard] = 1;//the card added to the deck will now = 1 so we know its been added already.
				int cardNum = getCard(randCard);//gives cardNum the value of a card
				deck.push_back(cardName[cardNum - 1]);//we place the num and its corresponding cardName in the deck. 
			}//end for

			
			

			//gives the player and dealer 2 cards each
			userCards.push_back(deck[0]);
			userCards.push_back(deck[1]);
			dealerCards.push_back(deck[2]);
			dealerCards.push_back(deck[3]);

			//we need to put the dealers second card face down so the user cannot see it	
			dealerHand = 0;
			userHand = 0;

			//output users hand
			/*takes users cards, adds them together and puts them in userHand
			this lets us to keep track of the users cards sum*/
			userHand = card[userCards[0]] + card[userCards[1]];

			//do the same with dealerHand
			dealerHand = card[dealerCards[0]] + card[dealerCards[1]];
			

			int count = 4;//starts at 4 because 4 cards are removed from deck from the beginning
			userChoice = ' ';//holds the users userChoice to stay (S) or hit(H)
			user_stay = false;
			dealer_stay = false;



			//while neither player has decided to STAY this loop runs.
			while (user_stay == false || dealer_stay == false)
			{
				cout << "===================STARTING COMPARISON=====\n" << endl;
				//display both players hands 
				cout << "Dealers Hand: ";
				displayDealerHand(dealerCards);//displays all cards with 1 face down.

				cout << "\n" << userName << "'s Hand: ";
				displayHand(userCards);//displays all cards
				cout << userName << " has: " << userHand << endl;



				//see if someone has blackjack already(if dealt an ace + 10,J,K or Q)
				if (userHand == 21)
				{
					cout << userName << " has Blackjack!" << endl;
					++userWins;
					break;
				}
				else if (dealerHand == 21)
				{
					cout << "Dealer has Blackjack !" << endl;
					cout << "\nDEALER HAND: ";
					displayHand(dealerCards);
					++dealerWins;
					break;
				}
				else if (dealerHand == 21 && userHand == 21)
				{
					cout << "Dealer: PUSH! Lucky this time " << userName << ",\nyou get your bet back." << endl;
					++drawCounter;
					break;
				}
				else if (userHand > 21)
				{
					cout << "Dealer: Jeeze, two aces, pretty rare." << endl;
					getAceValue(userHand);
					cout << "Dealer: you now have " << userHand << ".";
				}
				else if (dealerHand > 21)//the dealer has been dealt 2 aces
				{
					dealerHand -= 10;/*so we automatically make one of their values 1 because
										that is what any player would do */
				}//end if else


				//Ask user to hit or stay
				if (user_stay == false)
				{
					cout << "\nSo " << userName << ", will you hit or stay?\nEnter H or S: ";
					userChoice = ' ';//make userChoice null for next time through
					while (userChoice != 'H' && userChoice != 'S')
					{
						userChoice = ' ';
						cin >> userChoice;
						userChoice = toupper(userChoice);
					}//end inner while

				}//end if

				cout << "====================================" << endl;

				//flush buffer
				cin.clear();
				fflush(stdin);

				/*IF user choses to 'hit' we give them another card,
				ELSE they stay with what they have and we break the
				loop and compare their hand with the dealers*/
				if (userChoice == 'H')
				{

					cout << userName << " decides to hit." << endl;
					userCards.push_back(deck[count]);
					//CODE CHECK -- userCards.push_back("ACE");
					userHand += card[userCards[userCards.size() - 1]];
					++count;

					//if user gets an ACE we decide if its value is 1 or 11.
					if (userCards.back() == "ACE")
					{
						int &ref = userHand;
						getAceValue(ref);//call method to decide what the ace's value will be.
						cout << "\n" << endl;
					}//end inner if

					//display hand to user
					cout << userName << "'s Hand: ";
					displayHand(userCards);
					cout << userName << " has: " << userHand << endl;

					//if users new card puts their score over 21, user loses.
					if (userHand > 21)
					{
						cout << "Dealer: " << userName << " busts!" << endl;
						++dealerWins;
						break;
					}
					else if (userHand == 21)
					{
						cout << userName << " has Blackjack!" << endl;
						++userWins;
						break;
					}//end inner if else
				}
				else if (userChoice == 'S')
				{
					cout << userName << " decides to stay." << endl;
					user_stay = true;
				}//end outer if else


				/*if the dealers hand sum is < 17 they will take another card.
				This loop only runs when the dealer hasn't decided to stay.*/
				if (dealer_stay == false)
				{
					if (dealerHand <= 17)
					{
						cout << "\nDealer: I'll hit" << endl;
						dealerCards.push_back(deck[count]);
						dealerHand += card[dealerCards[dealerCards.size() - 1]];//adds one more card to dealers hand.
						++count;//increase count so the next card is different.

						//if dealers last card is an ace and it puts him over 21, dealer decides to make ACE value == 1.
						if (dealerCards.back() == "ACE" && dealerHand > 21)
						{

							dealerHand -= 10;//take 10 off of dealers sum
							cout << "\nDealer gets an ACE!\nDealer: I'll make its value a 1." << endl;
						}//end inner if

						//check dealers status for under 21, blackjack, or bust.
						if (dealerHand < 21)
						{
							cout << "DEALER HAND: ";
							displayDealerHand(dealerCards);
						}
						else if (dealerHand > 21)
						{
							cout << "DEALER HAND: ";
							displayHand(dealerCards);
							cout << "DEALER BUSTS, " << userName << " WINS!" << endl;
							++userWins;
							break;
						}
						else if (dealerHand == 21)
						{
							cout << "Dealer has Blackjack!" << endl;
							cout << "\nDEALER HAND: ";
							displayHand(dealerCards);
							++dealerWins;
							break;
						}//end inner if else
					}
					else//else dealer stays with current cards
					{
						cout << "\nDealer: I'll stay.\n";
						dealer_stay = true;
					}//end middle if else

				}//end outer if







				//if dealer and user decide to stay we see who wins.
				if (user_stay == true && dealer_stay == true)
				{
					//both players have decided to stay, display both hands and see who has won.
					cout << "\nDEALER HAND: ";
					displayHand(dealerCards);
					cout << userName << "'s Hand: ";
					displayHand(userCards);

					if (userHand > dealerHand)//if users hand is greater than dealers hand after both players decide to STAY
					{
						cout << userName << " wins!" << endl;
						++userWins;
						break;
					}
					else if (dealerHand > userHand)//if dealers hand is greater than users hand after both players decide to STAY
					{
						cout << "Dealer wins!" << endl;
						++dealerWins;
						break;//break out of inner loop
					}
					else if (dealerHand == userHand)//if both players have 21 no one wins
					{
						cout << "The game is a draw.\n" << userName << " you get your bet back." << endl;
						++drawCounter;
						break;
					}//end inner if else

				}//end outer if

			}//end inner while 

		}//end middle while

		//output game stats
		cout << "\n" << userName << "'s GAMES WON: " << userWins << "\nDEALER GAMES WON: " << dealerWins << "\n"
			"DRAWS: " << drawCounter << endl;

		cout << "================BEST=OF=THREE=HANDS=IS=OVER===================" << endl;

		//flush buffer
		cin.clear();
		fflush(stdin);

		/*if the user wins we return double their initial bet and we ask them if
		they want to play again, if they play again they keep their winnings,
		if not the game is reset.*/
		playAgain = ' ';
		if (userWins == 3)
		{
			cout << "\t================" << userName << " WINS POT================" << endl;
			//place users bet * 2 back in userPurse
			for (int i = 0; i < (userBet * 2); ++i)
			{
				userPurse.push_back(pokerChip);
			}//end for

			cout << userName << "'s PURSE: " << (userPurse.size() * pokerChip) << endl;
			cout << userName << " wins game, you get back double your bet! Play again?" << endl;

			//TEMP: userInput was used in the beginning, will set to null now to use for same purpose.
			while (playAgain != 'Y' && playAgain != 'N')
			{
				cout << "Enter Y or N: ";
				cin >> playAgain;
				playAgain = toupper(playAgain);
			}//end inner while

			if (playAgain == 'Y')
			{
				cout << "Alright lets keep playing." << endl;
			}
			else
			{
				cout << "GAME DONE" << endl;
				playing = false;
			}//end inner if else
		}
		else if (dealerWins == 3 && userPurse.empty())//user loses and their purse is empty they are forced to quit
		{
			cout << "\t================DEALER WINS POT================" << endl;
			cout << "You are BROKE " << userName << "! GET OUTTA MY CASINO!" << endl;
			playing = false;
		}
		else if (dealerWins == 3 && !userPurse.empty())
		{
			cout << "\t================DEALER WINS POT================" << endl;
			cout << "You lost this one " << userName << ".\nCut your loses or play again?" << endl;


			while (playAgain != 'P' && playAgain != 'Q')
			{
				playAgain = ' ';
				cout << "Enter Q to quit, or P to play again: ";
				cin >> playAgain;
				playAgain = toupper(playAgain);
			}//end while

			if (playAgain == 'P')
			{
				cout << "Alright lets keep playing." << endl;
			}
			else
			{
				cout << "GAME DONE" << endl;
				playing = false;
			}//end inner if else

		}//end outer if else

	}//end outer while


}//end startGame