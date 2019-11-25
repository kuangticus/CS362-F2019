// unit testing the ambassador function and functionality and for bugs
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
    int maxHandCount = 5;

    int k[10] = {adventurer, council_room, minion, ambassador, mine
                , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    int testHand[maxHandCount];
    testHand[0] = ambassador;  // minion card in hand
    for ( i = 1; i < maxHandCount; i++){
        testHand[i] = estate; // 4 curse cards
    }

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[0] = maxHandCount;
    memcpy(G.deck[0], testHand, sizeof(int) * maxHandCount); // 4 curse cards and ambassador
    memcpy(G.deck[1], testHand, sizeof(int) * maxHandCount); // 4 curse cards and ambassador

    for (i = 0; i < 5; i++) // draws 5 cards for the 2nd player
    {
        drawCard(1, &G);
    }

    printf("I will be testing the ambassador function out. \n");
    int oldSupply =  G.supplyCount[estate];
    int oldDeckCount = G.deckCount[1];

    case_ambassador( 2, 0, curse, 0, &G);

    // these asserts test whether the # of discarded cards will return to the stockpile
    if ( G.supplyCount[estate] == oldSupply + 2 )
        printf("%s\n", "We are expecting the supply of estates to increase by 2.");
    else
        printf("%s\n", "The stockpile of estate cards increased by more than 2.");

    // This will test whether the function adds cards correctly to other players +1
    if ( G.deckCount[1] == oldDeckCount + 1 )
        printf("%s\n", "The correct amount of cards discard got added to other players.");
    else
        printf("%s\n", "The incorrect amount of cards discard got added to other players. More than one got added.");

    return 0 ;
}

