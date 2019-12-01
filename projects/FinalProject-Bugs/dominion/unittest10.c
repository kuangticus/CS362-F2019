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
    testHand[0] = ambassador; 
    testHand[1] = copper;
    testHand[2] = baron;
    testHand[3] = estate;
    testHand[4] = curse;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount); 

    printf("Testing the cardEffect() case ambassador function.\n");
    
    int bonus;
    int checkRet = cardEffect(G.hand[cp][0], 4, 1, 0, &G, 0, &bonus);

    // We are chcking the return value of returned is 0 since we know the error is
    // the paramater checking stage.
    if ( checkRet != 0 )
        printf("There is an issue with the parameter checking.\n");
    
    if (checkRet == 0)
        printf("The code for checking parameters is working correcly.\n");
    else
        printf("The code for checking parameters is working incorrecly.\n");

    return 0;
}