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
  int k[10] = { estate, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

  const int seed = 125; // defining seed value
  const int maxNumPlayrs = 2; // defining maximum number of players

  // defining the state of game
  struct gameState G;

  printf("Unit Test - Remodel - Bug #3\n");

  memset(&G, 23, sizeof(struct gameState)); // clears the game state
  initializeGame(maxNumPlayrs, k, seed, &G); // this will initialize a new game

  // Initially declaring state of coins to be defined at value 0.
  G.coins = 0;
  G.playedCardCount = 0;

  const int finalRes = cardEffect(remodel, 0, 3, 0, &G, 0, 0); // calling cardEffect function to begin test, with remodel as case statement trigger

  // Checking to make sure that returned value from function call within case statement returns correct value.
  // If not, then correct and pass.
  if(finalRes == 0)
  {
    printf("Returned value from function (Actual): %d \t Returned value from function (Expected): 0 \t FAIL! \n", finalRes);
  }
  else
  {
    printf("Returned value from function (Actual): %d \t Returned value from function (Expected): -1 \t PASS! \n", finalRes);
  }

  // assert(finalRes == -1);

  if(finalRes == -1)
  {
    printf("Correct & Succesfull function of cardEffect with return value: %d\n", finalRes);
  }
  else
  {
    printf("Failed function call\n");
  }

  printf("End of Bug 3 Unit Test\n");

  return 0; // exiting test function
}
