// tesing the the baronCard function using this unit test
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p = 0, maxHandCount = 5;

    int k[10] = {adventurer, council_room, feast, gardens, mine
                , remodel, smithy, estate, baron, great_hall};
    struct gameState G;
    

    int testHand[maxHandCount];
    testHand[0] = baron;  // places baron in test
    testHand[1] = copper; // places copper
    testHand[2] = estate; // places estate
    testHand[3] = estate;
    testHand[4] = mine;     // places mine 
    

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[p] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.deck[p], testHand, sizeof(int) * maxHandCount); //1 baron, 1 copper, 2 estates, 1 mine
    for (i = 0; i < 5; i++) // draws the only five cards that are in the player's deck
    {
        drawCard(p, &G);
    }

    printf("I will be testing the the baron case statement in cardEffect(). \n");
    int numEstate = G.supplyCount[estate];
    int firstDeckCount = G.deckCount[p];

    baronCard(0, 1, &G);

    // custom assert for checking whether the code is working
    // will print the correct if the number of buy is correct ow wrong
    // limitation is that this test only works with initial setup where one buy is known
    if ( G.numBuys == 2 ) printf( "%d%s", G.numBuys, " buys is correct!\n"); 
    else printf( "%d%s", G.numBuys, " buys is wrong!\n");

    //customr assert, to check the amount of estate cards that are still there
    // the supply should have one less than before and handcount should be one more too 
    if ( G.supplyCount[estate] == numEstate-1 && G.deckCount[p] == firstDeckCount + 1 ) 
        printf("%d %d%s", G.supplyCount[estate], G.deckCount[p], "  # of estate cards in supply and current player deck is correct.\n");
    else 
        printf("%d %d%s", G.supplyCount[estate], G.deckCount[p], "  # of estate cards in supply and current player deck is wrong.\n");

    printf("Done with testing baron card function!\n");
}