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
                , remodel, baron, village, tribute, great_hall};
    struct gameState G;
    
    // for current player
    int testHand[maxHandCount];
    testHand[0] = tribute; 
    testHand[1] = copper;
    testHand[2] = baron;
    testHand[3] = estate;
    testHand[4] = estate;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount); 

    // for ease of testing I have made all the cards to be treasure cards
    for ( i =0 ; i < G.deckCount[cp+1]; i++){
        G.deck[cp+1][i] = copper; 
    }

    // has the next player draw 5 cards
    printf("Testing drawCard() this needs to work in order for the logic to work.\n");
    for ( i = 0; i < maxHandCount; i++){
        drawCard(cp+1, &G);
    }
    if ( G.handCount[cp+1] != 5)
        printf("Broken drawCard Logic.\n");
    assert( G.handCount[cp+1] == 5);

    printf("End of Testing drawCard().\n");

    printf("Testing cardEffect() tribute case statement.\n");
    int bonus;
    int initAction = G.numActions;

    cardEffect(G.hand[cp][0], 0, 0, 0, &G, 0, &bonus);

    if (initAction != G.numActions )
        printf("Something is not right with bonus logic handling! \n");
    
    if (initAction == G.numActions)
        printf("Code correcly handles a -1 index in the tributeRevealedCards.\n");
    else
        printf("Code incorrecly handles a -1 index in the tributeRevealedCards.\n");

    printf("End of testing for bug 9 cardEffect() tribute case statement. \n");

    return 0;
}