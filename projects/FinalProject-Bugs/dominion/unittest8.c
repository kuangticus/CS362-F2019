// Author: WeiHao Kuang

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxHandCount = 9, cp = 0; // cp is current player

    int k[10] = {adventurer, council_room, feast, ambassador, mine
                , remodel, smithy, village, baron, curse};
    struct gameState G;
    
    // for current player
    int testHand[maxHandCount];
    testHand[0] = baron; 
    testHand[1] = minion;
    testHand[2] = tribute;
    testHand[3] = embargo;
	testHand[4] = salvager;
	testHand[5] = steward;
    testHand[6] = estate;
    testHand[7] = estate;
    testHand[8] = estate;


	printf("Testing the baron case statement in cardEffect()!\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);
	// intialize the coins to zero to begin the game.
	G.coins = 0;
	int barCoins = G.coins;
	playCard(0, 1, 0, 0, &G); // play the card
	// printing the the before and after of the numbers
	printf( "%s%d%s%d\n", "initial Coins: ", barCoins, " After card coins: ", G.coins);

	// asserts to check the correct amount of coins that are added.
	if ( barCoins + 4 == G.coins )
		printf("The coin adding for baron is corrected 4 coins added.\n");
	else
		printf("The coin adding for baron is incorrect 4 coins were not added.\n");
	
	printf("Finished testing baron\n\n");
	/****************************************************************************************************/

	printf("Testing the minion case statement in cardEffect()!\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);
	// intialize the coins to zero to begin the game.
	G.coins = 0;
	int minCoins = G.coins;
	playCard(1, 1, 0, 0, &G);
	// printing the the before and after of the numbers
	printf( "%s%d%s%d\n", "initial Coins: ", minCoins, " After card coins: ", G.coins);

	// asserts to check the correct amount of coins that are added.
	if ( minCoins + 2 == G.coins )
		printf("The coin adding for minion is corrected 2 coins added.\n");
	else
		printf("The coin adding for minion is incorrect 2 coins were not added.\n");

	printf("Finished testing minion\n\n");
	/****************************************************************************************************/

	printf("Testing the tribute case statement in cardEffect()!\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);
	for ( i =0; i < 5; i++){
		drawCard(cp+1, &G);
	}
	for ( i =0; i < 5; i++){
		G.hand[cp+1][i] = gold;
		G.deck[cp+1][i] = gold;
	}

	// intialize the coins to zero to begin the game.
	G.coins = 0;
	int tribCoins = G.coins;

	//playing the tribute card.
	playCard(2, 0, 0, 0, &G);

	printf( "%s%d%s%d\n", "initial Coins: ", tribCoins, " After card coins: ", G.coins);
	if ( tribCoins + 2 == G.coins )
		printf("The coin adding for tribute card is corrected 2 coins added.\n");
	else
		printf("The coin adding for tribute card is incorrect 2 coins were not added.\n");

	printf("Finished testing tribute\n\n");
	/****************************************************************************************************/

	printf("Testing the embargo case statement in cardEffect()!\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);

	G.coins = 0;
	int embCoins = G.coins;

	playCard(3, 1, 0, 0, &G); // play the card

	// display the cards before and after
	printf( "%s%d%s%d\n", "initial Coins: ", embCoins, " After card coins: ", G.coins);

	// asserting whether that the coins are added correctly
	if ( tribCoins + 2 == G.coins )
		printf("The coin adding for embargo card is corrected 2 coins added.\n");
	else
		printf("The coin adding for embargo card is incorrect 2 coins were not added.\n");
	
	printf("Finished testing embargo\n\n");
	/****************************************************************************************************/
	
	printf("Testing the salvager case statement in cardEffect()!\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);

	G.coins = 0;
	int salCoins = G.coins;
	int coinsCost = getCost(G.hand[cp][3]);

	playCard(4, 3, 0, 0, &G); // play the card
	printf( "%s%d%s%d%s%d\n", "initial Coins: ", embCoins, " After card coins: ", G.coins, " Cost of embargo: ", coinsCost);

	if ( salCoins + coinsCost == G.coins )
		printf("%s%d%s", "The coin adding for embargo card is corrected ", coinsCost,  " coins added.\n");
	else
		printf("%s%d%s", "The coin adding for embargo card is incorrect ", coinsCost, " coins were not added.\n");
	
	printf("Finished testing salvage.\n\n");
	/****************************************************************************************************/
	printf("Testing the steward case statement in cardEffect()!\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);

	G.coins = 0;
	int stewCoins = G.coins;

	playCard(5, 2, 0, 0, &G); // play the card

	printf( "%s%d%s%d\n", "initial Coins: ", embCoins, " After card coins: ", G.coins);

	if ( stewCoins + 2 == G.coins )
		printf("The coin adding for embargo card is corrected 2 coins added.\n");
	else
		printf("The coin adding for embargo card is incorrect 2 coins were not added.\n");
	
	printf("Finished testing steward.\n");
	/****************************************************************************************************/


	



	
	






	
	
	






	

    return 0;
}