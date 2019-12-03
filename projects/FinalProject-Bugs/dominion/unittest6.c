#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int maxHandCount = 5, cp = 0; // cp is current player

    int k[10] = {adventurer, council_room, feast, ambassador, mine
                , remodel, smithy, village, baron, curse};
    struct gameState G;
    
    // for current player
    int testHand[maxHandCount];
    testHand[0] = feast; 
    testHand[1] = estate;
    testHand[2] = estate;
    testHand[3] = estate;
    testHand[4] = estate;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);

	printf("Testing the feast case for the code.\n");

	int curCoins = G.coins;
	printf("Current Coins %d\n", curCoins);

	// this will setup the code to call the feast card.

	int bonus;
	cardEffect(G.hand[cp][0], 0, 0, 0, &G, 0, &bonus);

	// if the logic is correct
	if ( curCoins == G.coins){
		printf("The there is a correct amount of coins for the current player.\n");
		printf("The current logic does not add unncessary coins to the game.\n");
		
	}
	// if the logic is incorrect
	else{
		printf("The there is an inorrect amount of coins for the current player.\n");
		printf("The current logic is adding unncessary coins to the cur player.\n");
	}
		
    return 0;
}