//Steve Walker COPYRIGHT!!!
//No one can steal this masterpiece.
//I'll sell it for a 2 bucks though.

#include <iostream>
#include <string>
#include "Blackjack.h"

using namespace std;

int main()
{
	string userName;

	cout << "BLAAAAAACK....JAAAAAAAACK!\nEnter your name and we can begin: ";
	cin >> userName;
	
	Blackjack blackjack(userName);
	blackjack.startGame();

	
}//end main