
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
	// int i, j, r, b, c;
	// set your card array
	int k[10] = { feast, province, estate, duchy, mine , remodel, smithy, village, curse, baron };
	// declare the game state. Set feast as the first card on hand.
	struct gameState G;
	// declare the arrays of all coppers, silvers, and golds

	printf("Testing the cardEffect() case feast.\n");

	int seed = rand() % 100;//initialize random seed

	//test scoreFor()
	// set the state of your variables so that you will trigger the bug for feast
	memset(&G, 23, sizeof(struct gameState)); // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game. Set num of players to 2. 

	//change starting coins
	G.coins = 6; //Make coins on hand equals to 6.

	//play feast to gain an estate(which should be successful)
	cardEffect(G.hand[0][0], estate, 0, 0, &G, 0, 0);

	//see if coin has changed after played feast
	if (G.coins == 6)
		printf("feast is working correctly while feast works.\n");
	else
		printf("feast changed the current coins while feast works. It is not working correctly.\n");

	//play feast to gain an Adventurer(cost 6, which should be failure)
	cardEffect(G.hand[0][0], adventurer, 0, 0, &G, 0, 0);

	//see if coin has changed after played feast
	if (G.coins == 6)
		printf("feast is working correctly while feast failed.\n");
	else
		printf("feast changed the current coins while feast failed. It is not working correctly.\n");

	printf("Ending Testing cardEffect() case feast.\n");
	return 0;
}