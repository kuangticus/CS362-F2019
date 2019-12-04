CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 unittest5 unittest6 unittest7 unittest8 unittest9 unittest10  

unit1: unittest1.c dominion.o rngs.o 
	gcc  -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unit2: unittest2.c dominion.o rngs.o 
	gcc  -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	
unit3: unittest3.c dominion.o rngs.o 
	gcc  -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unit4: unittest4.c dominion.o rngs.o 
	gcc  -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
unit5: unittest5.c dominion.o rngs.o 
	gcc  -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)

unit6: unittest6.c dominion.o rngs.o 
	gcc  -o unittest6 -g unittest6.c dominion.o rngs.o $(CFLAGS)
	
unit7: unittest7.c dominion.o rngs.o 
	gcc  -o unittest7 -g unittest7.c dominion.o rngs.o $(CFLAGS)

unit8: unittest8.c dominion.o rngs.o 
	gcc  -o unittest8 -g unittest8.c dominion.o rngs.o $(CFLAGS)
	
unit9: unittest9.c dominion.o rngs.o 
	gcc  -o unittest9 -g unittest9.c dominion.o rngs.o $(CFLAGS)

unit10: unittest10.c dominion.o rngs.o 
	gcc  -o unittest10 -g unittest10.c dominion.o rngs.o $(CFLAGS)

unittestresults: unit1 unit2 unit3 unit4 unit5 unit6 unit7 unit8 unit9 unit10
	./unittest1	>> unittestresults.out
	gcov -b -f unittest1 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest2	>> unittestresults.out
	gcov -b -f unittest2 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest3	>> unittestresults.out
	gcov -b -f unittest3 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest4	>> unittestresults.out
	gcov -b -f unittest4 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest5	>> unittestresults.out
	gcov -b -f unittest5 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest6	>> unittestresults.out
	gcov -b -f unittest6 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest7	>> unittestresults.out
	gcov -b -f unittest7 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest8	>> unittestresults.out
	gcov -b -f unittest8 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest9	>> unittestresults.out
	gcov -b -f unittest9 >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest10	>> unittestresults.out
	gcov -b -f unittest10 >> unittestresults.out
	echo "" >> unittestresults.out
