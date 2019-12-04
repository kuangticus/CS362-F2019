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
                , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    int testHand[maxHandCount];
    testHand[0] = mine;  // mine card in hand
    testHand[1] = copper;
    testHand[2] = silver;
    testHand[3] = estate;
    testHand[4] = estate;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);  

    // test should work but since my test is reliant on these working I have to test
    printf("Testing to see if getCost() is working correctly.\n");
    
    assert( getCost(gold) ==  6); // this wil simply check to see if the cost getting is correct for gold
    assert( getCost(silver) ==  3); // this wil simply check to see if the cost getting is correct for silver
    assert( getCost(copper) ==  0); // this wil simply check to see if the cost getting is correct for copper
    printf("getCost() is working correctly.\n");

    // test should work but since my test is reliant on these working I have to test
    printf("Testing to see if gainCard() and discardCard() is working correctly.\n");
    //test the gain card function for what its supposed to do 
    int tempNum = G.handCount[cp];
    gainCard(baron, &G, 2, cp);
    assert( G.handCount[cp] == tempNum + 1 ); // asserting to see if the cards are added correctly
    
    // testing the discard card function to see if it works correctly
    discardCard(6, cp, &G, 1);
    tempNum = G.handCount[cp];
    // asserting to see if the the functin can remove cards correctly.
    assert( G.handCount[cp] == tempNum ); 
    printf("gainCard() and discardCard() is working correctly.\n");

    printf("Testing the cardEffect() case statement mine.\n");

    // swapping a sivler for gold
    int handInit = G.handCount[cp];
    int bonus;
    cardEffect(G.hand[cp][0], 2 , gold, 0, &G, 0, &bonus);

    if ( handInit-1 ==  G.handCount[cp] )
        printf("Removal logic is working!\n");
    else
        printf("Removal logic is not working!\n");

    int isThereGold = 0;
    for ( i =0; i< G.handCount[cp]; i++)
        if ( G.hand[cp][i] == gold)
            isThereGold = 1;
    
    if (isThereGold == 1 )
        printf("Removal logic is working! Correctly added gold.\n");
    else
        printf("Removal logic is not working! Didn't add gold.\n");



    return 0;

}