// Unit testing minion Function for functionality
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
    testHand[0] = minion;  // minion card in hand
    for ( i = 1; i < maxHandCount; i++){
        testHand[i] = copper; // copper treasure (4) cards
    }

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[0] = maxHandCount;
    memcpy(G.deck[0], testHand, sizeof(int) * maxHandCount); //4 coppers and minion
    
    printf("I will be testing the minion card function. \n");

    int amtCoins = G.coins;
    case_minion( 0, 0, 1, 0, &G);
    // checking that there 2 coins added like there should be from the card rule
    // if the incorrect amount of coins are added the code will say how much extra is added
    if (G.coins == amtCoins + 2)
        printf("%s", "2 coins were correctly added to the current player!\n");
    else
        printf( "%d%s", G.coins - amtCoins - 2, " extra coins were added\n");


    printf("I will be testing the minion card function. \n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[0] = maxHandCount;
    memcpy(G.deck[0], testHand, sizeof(int) * maxHandCount); //4 coppers and minion
    memcpy(G.deck[1], testHand, sizeof(int) * maxHandCount); 

    for (i = 0; i < 3; i++) // draws the only 2 card for player 2
    {
        drawCard(1, &G);
    }

    case_minion( 0, 0, 2, 0, &G);

    // this will test whether the code is working so that when ther people with more than 5 card will get
    // their hand replaced, people with less than 4 cards will not have to get their hand replaced
    // for the bug I implanted people with more than 2 have to replace their hand.
    if ( G.handCount[1] > 2)
        printf("%s", "Someone with less than 4 cards had to replace their cards when they don't have to.\n");
    else
        printf("%s", "The program is working like it should be.\n");

    return 0;
    
}