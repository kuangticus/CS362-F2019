// Unit test the mineCard function for functionality
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
    int maxHandCount = 5, p = 0;

    int k[10] = {adventurer, council_room, feast, ambassador, mine
                , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    int testHand[maxHandCount];
    testHand[0] = mine;  // mine card in hand
    for ( i = 1; i < maxHandCount; i++){
        testHand[i] = copper; // silver treasure (4) cards
    }
    
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[p] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.deck[p], testHand, sizeof(int) * maxHandCount); //4 coppers 

    printf("I will be testing the mineCard function. \n");

    case_mine( 0, testHand[2], gold, 0, &G);

    // Checks to see if the cards can be added when the card i am trading for is more than 3x as much
    int count = 0;
    for ( i = 0; i < G.handCount[0]; i++){
        if ( G.hand[0][i] == gold)
            count += 1;
    }

    // this statements check to see if the gold was added from trading copper, the thing should
    // say that it is traded correctly since that the bug that i am trying to expose
    if ( count >= 1 ){
        printf("%s\n", "Gold was added even though we used copper to trade up.");
         // this if statement will check to see if we are than one cards added from the trade
        if( count > 1)
            printf("%d%s\n", count, " cards where added." );
    }
    else
        printf("%s\n", "Nothing was added and the program is working");
    
    printf("Done with testing the mine card!\n");
}
