// unit testing the tribute function and functionality and for bugs
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
    testHand[0] = tribute;  // tribute card in hand
    testHand[1] = mine; // mine card
    testHand[2] = baron; // baron
    testHand[3] = copper; // copper
    testHand[4] = estate; // estate

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[0] = maxHandCount;
    memcpy(G.deck[0], testHand, sizeof(int) * maxHandCount); 
    memcpy(G.deck[1], testHand, sizeof(int) * maxHandCount); 

    for (i = 0; i < 5; i++) // draws 5 cards for the 2nd player
    {
        drawCard(1, &G);
    }

    printf("I will be testing the tribute function out. \n");
    int tributeRevealedCards[2];
    int prevCardNum = G.handCount[0];
    case_tribute(0, 1, &G, tributeRevealedCards );

    // this is chekcing to see if the correct number of thing extra cards are added from the treasure card tributes
    if ( prevCardNum + 2 == G.handCount[0])
        printf("%s\n", "The right amount of cards have been added to the the current player's hand.");
    else 
        printf("%d%s\n", G.handCount[0] - prevCardNum - 2, " extra cards added to cur player's hand.");

    // this checks if the duplicates are removed correct from tribute bank

    if ( tributeRevealedCards[1] == -1)
        printf( "%s\n", "The duplicate remove logic is not working correctly.");
    else 
        printf("%s\n", "The removing of duplicates is correct and working the way we designed.");

    return 0;

}

     