// internally developed files
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

// external files
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

// main function to start program
int main(int argc, char const *argv[])
{
    // set your card array
    int k[10] = { adventurer, ambassador, embargo, village, minion, mine, cutpurse, baron, tribute, smithy };

    const int playPersonOne = 0; // defining player one
    const int playPersonTwo = 1; // defining player two

    const int maxNumPlayrs = 2; // defining maximum number of players
    const int seed = 127; // defining seed value

    // defining the state of game
    struct gameState G;

    printf("Unit Test - Tribute - Bug #7\n");

    memset(&G, 23, sizeof(struct gameState)); // clears the game state
    initializeGame(maxNumPlayrs, k, seed, &G); // this will initialize a new game
    // Defining the hand for playPersonOne
    // handCount intialized to 5
    // hand, 4 copper, 1 tribute
    G.handCount[playPersonOne] = 5;
    G.hand[playPersonOne][0] = copper;
    G.hand[playPersonOne][1] = copper;
    G.hand[playPersonOne][2] = copper;
    G.hand[playPersonOne][3] = copper;
    G.hand[playPersonOne][4] = tribute;


    // Defining hand for playPersonTwo
    // discardCount initialized to 0 initially
    // deckCount intialized to 10 initially
    // deck 7 through 9 - village
    G.discardCount[playPersonTwo] = 0;
    G.deckCount[playPersonTwo] = 10;
    G.deck[playPersonTwo][7] = village;
    G.hand[playPersonTwo][8] = village;
    G.hand[playPersonTwo][9] = village;

 



    const int finalRes = cardEffect(tribute, 0, 0, 0, &G, 4, 0); // calling cardEffect function to begin test, with tribute as case statement trigger

     printf("s dfsdffsdf \n");

    // Checking to make sure that numActions state value is equal to 3 to pass
    // If not, then incorrect and fails.
    if(G.numActions == 3)
    {
        printf("# of Actions (Actual): %d \t # of Actions (Expected): 3 \t PASS! \n", G.numActions);

    }
    else
    {
        printf("# of Actions (Actual): %d \t # of Actions (Expected): 3 \t FAIL! \n", G.numActions);
    }
    

    if(finalRes == 0)
    {
      printf("Correct & Succesfull function of cardEffect with return value: %d\n", finalRes);
    }
    else
    {
      printf("Failed function call\n");
    }

    // Checking to make sure that coins state value is correct
    // If not, then incorrect and fails.
    // if(G.coins == 5)
    // {
    //     printf("# of Coins (Actual): %d \t # of Coins (Expected): 5 \t PASS! \n", G.coins);
    // }
    // else
    // {
    //     printf("# of Coins (Actual): %d \t # of Coins (Expected): 5 \t FAIL! \n", G.coins);
    // }

    printf("End of Bug 7 Unit Test\n");

    return 0; // exiting test function
}
