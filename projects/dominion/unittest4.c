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

  const int seed = 126; // defining seed value
  const int maxNumPlayrs = 2; // defining maximum number of players
  int incrTrav;// used for traversal in for loop of supply cards

  // defining the state of game
  struct gameState G;

  printf("Unit Test - isGameOver - Bug #4\n");

  memset(&G, 23, sizeof(struct gameState)); // clears the game state
  initializeGame(maxNumPlayrs, k, seed, &G); // this will initialize a new game

  // Initially declaring state of coins to be defined at value 0.
  G.coins = 0;

  for(incrTrav = 0; incrTrav < 27; incrTrav++)
  {
    if(incrTrav == 26 || incrTrav == 25 || incrTrav == 24)
    {
      G.supplyCount[incrTrav] = 0;
    }
    else
    {
      G.supplyCount[incrTrav] = 1;
    }
  }

  const int finalRes = isGameOver(&G); // calling isGameOver function and storing returned value from func

  // Basically checking for returned value for 1, since j is incremented for the for loop above and if j >= 3 return 1;
  // Else return 0;
  // Checking to make sure that returned value is correct or not
  // If not, then correct and passes.
  if(finalRes == 0)
  {
    printf("Returned value (Actual): %d \t Returned value (Expected): 1 \t FAIL! \n", G.numActions);

  }
  else
  {
    printf("Returned value (Actual): %d \t Returned value (Expected): 1 \t PASS! \n", G.numActions);
  }

  if(finalRes == 0 || finalRes == 1)
  {
    printf("Correct & Succesfull function of cardEffect with return value: %d\n", finalRes);
  }
  else
  {
    printf("Failed function call\n");
  }

  printf("End of Bug 4 Unit Test\n");

  return 0; // exiting test function
}