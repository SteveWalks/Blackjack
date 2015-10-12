# Blackjack
This is a text-based Blackjack game written in C++ for Programming With C++ (Year 1).


# Requirements Report Summary

// SECTION A  Executive Summary 

The card game I have chosen to program is called Blackjack. I have chosen this game for two reasons: I feel that I would code this game better than other options, and after looking at several different games I came to the conclusion that Blackjack would be the most enjoyable for the user. Blackjack requires strategy from the player as well as a bit of luck and difficult choice making, which I believe will keep the user interested in the game. 


// SECTION B  Rules of Blackjack:

  •	Player vs Dealer(computer)
  •	Standard 52 cards.
  •	Card Values:
    - 2 – 10 have their face values
    - J, Q, K are 10 points each
    - Ace is 1 or 11 (user’s choice)
    
The premise is simple, players place their bets, whoever’s cards sum is closest to 21 without going over wins the hand,   best of 5 hands wins the betting’s.

The game begins with the player being dealt 2 cards face-up, and the dealer being dealt 2 cards (1 face-up and 1 face-down). 

The player decides whether they would like another card (HIT), or stick with what they have (STAY). A player may take as many cards as they would like as long as they do not go over 21 (which is a BUST), in which case they automatically lose.

If the player is dealt an ACE and a J, Q or K they have got BLACKJACK, which means they automatically win the hand, unless the dealer has BLACKJACK as well. 

If both the player and the dealer acquire a BLACKJACK, the result is a PUSH for the player, which means the player gets back their initial bet.

The player cannot play anymore once they run out of poker chips.


// SECTION C  Implementation

Data Structures and Class Features:
I will be creating a Blackjack class which will contain several methods including: a shuffle method to shuffle the cards, a bet method which will take in an int representing the amount of chips you would like to bet, as well as a displayHand method to display players cards, and a distributeCard method which will distribute a card to player.

I will be using the following Data structures to program Blackjack:
  1.	Header Files - to keep my Blackjack class organized
  2.	Operator/Function Overloading - which I will use for several functions
  3.	Enumerators 
  4.	Deques – which I will use to hold the dealers
  5.	Recursion
  6.	Maps – I will be using maps to organize my suits
  7.	Vector – which I plan to use to hold player and dealers cards


User Interface Flow:

The program begins with the user being asked if they would like to quit early or start the game. If the user presses Q the program ends, if they press S the game starts.

Once the game has started the player is given 10 poker chips ($100 each), the player is then asked how much they would like to bet. Once the bets have been placed the player and computer are dealt 2 cards each.

A check is done to see if the player or dealer is dealt a BLACKJACK hand. If one person has BLACKJACK they win. If BOTH players get BLACKJACK, the hand ends and the players bet is returned to them. If no one has BLACKJACK the player is asked if they would like to HIT or STAY.

Best of 5 hands wins the betting’s. The user’s poker chips are then counted, if the user’s PURSE is 0, they are kicked out of the Casino and the program ends. If the user has poker chips left to bet the player is asked to play another round of Blackjack.


// SECTION D  Test Cases

Typical Cases:
  •	If a player gets Blackjack.
  •	If dealer or player’s hand is closest to 21.	
  •	If player BUSTS. 

Boundary Cases:
  •	If BOTH players have Blackjack.
  •	If both players STAY and their cards are equal but less than 21.
  •	If player bets all of their chips.
  •	If player bets nothing
  
Bad Data: 
  •	If player bets over their total chips.
  •	If player tries to enter a negative value as their bet.
  •	If user enters a letter other than Q or S before game begins.









