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
    for ( i = 1; i < maxHandCount; i++){
        testHand[i] = copper; // silver treasure (4) cards
    }
    
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[cp] = maxHandCount;                 // set the number of cards on hand
    memcpy(G.hand[cp], testHand, sizeof(int) * maxHandCount);  

    // test should work but since my test is reliant on these working I have to test
    printf("Testing to see if getCost() is working correctly.\n");
    if ( getCost(gold) ==  6 && getCost(silver) ==  3 && getCost(copper) ==  0 )
        printf("getCost() is working correctly.\n");
    
    assert( getCost(gold) ==  6); // this wil simply check to see if the cost getting is correct for gold
    assert( getCost(silver) ==  3); // this wil simply check to see if the cost getting is correct for silver
    assert( getCost(copper) ==  0); // this wil simply check to see if the cost getting is correct for copper
    printf("getCost() is working correctly.\n");

    // test should work but since my test is reliant on these working I have to test
    printf("Testing to see if gainCard() and discardCard() is working correctly.\n");
    //test the gain card function for what its supposed to do 
    int tempNum = G.handCount[cp];
    gainCard(baron, &G, 2, cp);
    if ( G.handCount[cp] == tempNum + 1)
        printf("gainCard() is working correctly.\n"); 
    assert( G.handCount[cp] == tempNum + 1 ); // asserting to see if the cards are added correctly
    
    // testing the discard card function to see if it works correctly
    discardCard(6, cp, &G, 1);
    tempNum = G.handCount[cp];
    // asserting to see if the the functin can remove cards correctly.
    if( G.handCount[cp] == tempNum )
        printf("discardCard() is working correctly.\n");
    assert( G.handCount[cp] == tempNum ); 
    printf("End of testing gainCard() and discardCard().\n");


    printf("Testing to see if cardEffect() mine case is working correctly.\n");
    int bonus;
    // since we know that the only combination that should not work is the copper to gold
    int checkRet = cardEffect(G.hand[cp][0], 1 , gold, 0, &G, 0, &bonus);

    if (checkRet == -1)
        printf("carEffect Mine case is working correctly.\n");
    // this just basically checks the return value of card effect this should
    // return -1 when when copper to silver is inputted
    // copper tp gold should not work, if it works then something is wrong
    
    if (checkRet == -1)
       printf("cardEffect() mine case is working correctly.\n");
    else
       printf("cardEffect() mine case is not working correctly.\n");

    return 0;

}