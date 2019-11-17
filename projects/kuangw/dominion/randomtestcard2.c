// this one if for the minion random test generator

// including all the neccessary things to get the program working
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int k[10] = {adventurer, council_room, feast, gardens, mine
                , remodel, minion, estate, baron, great_hall};

int *randomStartHand(){
    int *hand = malloc(sizeof(int)*5);
    int i;
    for (i = 0; i < 5; i++){
        hand[i] = k[rand()%10];
    }
    return hand;
}

int *randomChoice()
{
    int *choice = malloc(sizeof(int)*2); // allocates space for 2 choices
    choice[0] = rand()%2; // randomly chooses the first option
    choice[1] = rand()%2; // randomly chooses the first option
    return choice; // returns the choice array
}

int *randomPos()
{
    int *pos = malloc(sizeof(int));
    *pos = rand()%5;
    return pos;
}

int main () {
    int i, count=0;
    int seed = 1000;
    int numPlayer = 2;
    int p = 0, maxHandCount = 5;
    srand(time(NULL));
    struct gameState G;
    int *testhand, *choice, *pos;

    while (1) {
        testhand = randomStartHand();
        choice = randomChoice();
        pos = randomPos();
        
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.deckCount[p] = maxHandCount;                 // set the number of cards on hand
        memcpy(G.deck[p], testhand, sizeof(int) * maxHandCount);  // randomhand for testing

        for (i = 0; i < 5; i++) // draws the only five cards that are in the player's deck
        {
            drawCard(p, &G);
        }

        printf("%s%d%s", "I will be testing the the baronCard for correct coin addition. Test: ", count+1, " \n");

        // testing the minion function
        // random inputs to the function that I made.
        int amtCoins = G.coins;
        minionCard(choice[0], choice[1], p, *pos, &G);

        // only works when the random numbers are 1 and 0
        if ( choice[0] == 1 && choice[1] == 0 ){

            // the following conditionals are used to check for the correct coin adding.
            if (G.coins == amtCoins + 2)
            {
                printf("%s", "2 coins were correctly added to the current player!\n");
                break;
            }
            else {
                printf( "%d%s", G.coins - amtCoins - 2, " extra coins were added which is wrong.\n");       
                break;
            }
        }
        else
            printf("%s", "The input is incorrect!\n");

        count++;
        free(testhand);
        free(choice);
        free(pos);
    }
    count = 0;
    while (1){

        testhand = randomStartHand();
        choice = randomChoice();
        pos = randomPos();

        printf("%s%d%s", "I will be testing the the baronCard for the correct hand redraw functionality Test: ", count+1, " \n");
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.deckCount[p] = maxHandCount;                 // set the number of cards on hand
        memcpy(G.deck[p], testhand, sizeof(int) * maxHandCount);  // randomhand for testing
        memcpy(G.deck[p+1], testhand, sizeof(int) * maxHandCount); 

        for (i = 0; i < 3; i++) // draws the only 2 card for player 2
        {
            drawCard(1, &G);
        }

        minionCard(choice[0], choice[1], p, *pos, &G);

        // this will test whether the code is working so that when ther people with more than 5 card will get
        // their hand replaced, people with less than 4 cards will not have to get their hand replaced
        // for the bug I implanted people with more than 2 have to replace their hand.
        if ( choice[1] == 1 && choice[0] == 0 ){
            if ( G.handCount[1] > 2)
            {
                printf("%s", "Someone with less than 4 cards had to replace their cards when they don't have to.\n");
                break;
            }
            else 
            {
                printf("%s", "The program is working like it should be.\n");
                break;
            }
        }
        else
            printf("%s", "The input is incorrect!\n");
        count++;
        // freeing dynamic memory each iteration
        free(testhand);
        free(choice);
        free(pos);
    }
    return 0;
}