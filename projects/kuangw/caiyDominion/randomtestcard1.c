// this one is for the baron card random generator
// for this random test I will always be testing in the perspective of the current player

// including all the neccessary things to get the program working
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// this is my random test generator for the starting hand
int *randomStartHand(int *k)
{
    
    int *hand = malloc(sizeof(int)*5); // dynamically allocation spacee for cards
    int i;
    // choose five random cards.
    for (i = 0; i < 5; i++)
    { 
        hand[i] = k[rand()%10];
    }
    return hand; // returns the randomly generated hand
}

// this is the random test generator for the choices 
int *randomChoice()
{
    int *choice = malloc(sizeof(int)); // allocates space for 2 choices
    *choice = rand()%2; // randomly chooses the first option
    return choice; // returns the choice array
}

int main () 
{   
    int k[10] = {adventurer, council_room, feast, gardens, mine
                , remodel, smithy, estate, baron, great_hall};
    int i, count=0;
    int seed = 1000;
    int numPlayer = 2;
    int p = 0, maxHandCount = 5;
    srand(time(NULL));
    struct gameState G;
    int *testhand, *choice;

    while (1) 
    {
        testhand = randomStartHand(k);
        choice = randomChoice();
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.deckCount[p] = maxHandCount;                 // set the number of cards on hand
        memcpy(G.deck[p], testhand, sizeof(int) * maxHandCount);  // randomhand for testing

        for (i = 0; i < 5; i++) // draws the only five cards that are in the player's deck
        {
            drawCard(p, &G);
        }

        printf("%s%d%s", "I will be testing the the baron case statement in cardEffect(). Test: ", count+1, " \n");
        int numEstate = G.supplyCount[estate];
        int firstDeckCount = G.deckCount[p];
        case_baron(*choice, 1, &G);
        

        if ( G.numBuys == 2 ) 
        {
            printf( "%d%s", G.numBuys, " buys is correct!\n"); 
            break;
        }
        else 
        {
            printf( "%d%s", G.numBuys, " buys is wrong!\n");
            break;
        }

        if ( G.supplyCount[estate] == numEstate-1 && G.deckCount[p] == firstDeckCount + 1 ) {
            printf("%d %d%s", G.supplyCount[estate], G.deckCount[p], "  # of estate cards in supply and current player deck is correct.\n");
            break;
        }
            
        else {
            printf("%d %d%s", G.supplyCount[estate], G.deckCount[p], "  # of estate cards in supply and current player deck is wrong.\n");
            break;
        }

        count++;

        // freeing memory to avoid problems if the program runs too long.        
        free(testhand);
        free(choice);
    }
    return 0;
}