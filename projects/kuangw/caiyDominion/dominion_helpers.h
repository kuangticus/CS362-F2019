#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
                int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3,
               struct gameState *state, int handPos, int *bonus);
int case_baron(int currentPlayer, int choice1, struct gameState *state);
int case_minion( int currentPlayer, int choice1, int choice2, int handPos, struct gameState *state);
int case_ambassador(int currentPlayer, int choice1, int choice2,  int handPos, struct gameState *state);
int case_tribute( int currentPlayer, int nextPlayer, struct gameState *state, int *tributeRevealedCards);
int case_mine(int currentPlayer, int choice1, int choice2, int handPos, struct gameState *state);
#endif
