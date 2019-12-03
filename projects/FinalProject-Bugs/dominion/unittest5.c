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
    int maxHandCount = 5, cp = 0; // cp is current player

    int k[10] = {adventurer, council_room, feast, ambassador, mine
                , remodel, smithy, village, baron, curse};
    struct gameState G;
    
    // for current player
    int testHand[maxHandCount];
    testHand[0] = estate; 
    testHand[1] = estate;
    testHand[2] = estate;
    testHand[3] = estate;
    testHand[4] = estate;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.deck[cp], testHand, sizeof(int) * maxHandCount);
	drawCard(cp, &G);

	// the for loop below are for the initial check we should follow
	// can compared the the current logic to
	int count1 =0 ;
	for ( i=0; i <G.deckCount[cp]; i++){
		if ( G.deck[cp][i] == estate )
			count1++;
	}
	printf("Deck estates %d\n", count1);

	int count2 =0;

	for ( i=0; i <G.handCount[cp]; i++){
		if ( G.hand[cp][i] == estate )
			count2++;
	}
	printf("Hand Estates %d\n", count2);

	int count3 =0;
	for ( i=0; i <G.discardCount[cp]; i++){
		if ( G.hand[cp][i] == estate )
			count3++;
	}
	printf("Discarded Estates %d\n", count3);

	// the score of this will be right since it is playing by the rules
	printf("ScoreFor current player should be %d\n", count1 + count2 + count3);
	
    printf("Testing the scoreFor function.\n");

	// this will call the score card function;
	int curScore = scoreFor(cp, &G);

	// checks to see if the score is correct if not says so
	if ( curScore != count1 + count2 + count3)
		printf("Score function is wrong!\n");
	else
		printf("Score function is right!\n");
    
    return 0;
}