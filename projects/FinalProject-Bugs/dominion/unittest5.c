
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	int  i; // j, b, c;
	// set your card array
	int handcount = 5, cp = 0;//hand count and currentplayer
	int deckestate = 0, handestate = 0, discardestate = 0;
	int k[10] = { copper, silver, gold, feast, mine , remodel, smithy, village, adventurer, baron };
	// declare the game state. No victory card.
	struct gameState G;
	// declare the arrays of all coppers, silvers, and golds

	printf("Testing the scoreFor() case.\n");

	int seed = rand() % 100;//initialize random seed

	int testHand[handcount];
	testHand[0] = mine;
	testHand[1] = copper;
	testHand[2] = silver;
	testHand[3] = estate;
	testHand[4] = estate;//2 states on hand, means 2 points

	//test scoreFor()
	// set the state of your variables.
	memset(&G, 23, sizeof(struct gameState)); // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game. Set num of players to 2. 
	G.deckCount[cp] = handcount;
	memcpy(G.hand[cp], testHand, sizeof(int) * handcount);
	drawCard(cp, &G);//draw cards first, or scoreFor won't return any information

	//get number of estates from players' decks, hand, and discard
	deckestate = 0;
	for (i = 0; i < G.deckCount[cp]; i++) {
		if (G.deck[cp][i] == estate)
			deckestate++;
	}

	handestate = 0;
	for (i = 0; i < G.handCount[cp]; i++) {
		if (G.hand[cp][i] == estate)
			handestate++;
	}

	discardestate = 0;
	for (i = 0; i < G.discardCount[cp]; i++) {
		if (G.discard[cp][i] == estate)
			discardestate++;
	}
	
	printf("Estate on deck: %d, hand: %d, discard: %d\n", deckestate, handestate, discardestate);
	printf("The score should be %d\n", deckestate + handestate + discardestate);
	//test original score
	printf("The scoreFor() prints %d\n", scoreFor(cp, &G));

	//test 2: discard 3 times and make discard bigger than deck
	//initialize a new game
	// set the state of your variables.
	memset(&G, 23, sizeof(struct gameState)); // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game. Set num of players to 2. 
	G.deckCount[cp] = handcount;
	memcpy(G.hand[cp], testHand, sizeof(int) * handcount);
	drawCard(cp, &G);//draw cards first, or scoreFor won't return any information
	gainCard(mine, &G, 0, cp); //player 0 discards a mine
	gainCard(estate, &G, 2, cp); //player 0 hands an estate

	deckestate = 0;
	for (i = 0; i < G.deckCount[cp]; i++) {
		if (G.deck[cp][i] == estate)
			deckestate++;
	}

	handestate = 0;
	for (i = 0; i < G.handCount[cp]; i++) {
		if (G.hand[cp][i] == estate)
			handestate++;
	}

	discardestate = 0;
	for (i = 0; i < G.discardCount[cp]; i++) {
		if (G.discard[cp][i] == estate)
			discardestate++;
	}

	printf("Estate on deck: %d, hand: %d, discard: %d\n", deckestate, handestate, discardestate);
	printf("The score should be %d\n", deckestate + handestate + discardestate);
	//test original score
	printf("The scoreFor() prints %d\n", scoreFor(cp, &G));




	printf("Ending Testing scoreFor()\n");
	return 0;
}