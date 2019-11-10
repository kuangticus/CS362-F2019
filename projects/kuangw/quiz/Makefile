default: randomtest

randomtest:
	gcc -std=c99 -o randomtest testme.c
	./randomtest

cCompile:
	gcc -ftest-coverage -fprofile-arcs -std=c99 -o coveragetest testme.c
	./coveragetest

coverage:
	gcov testme.c

clean: 
	rm coveragetest randomtest testme.c.gcov testme.gcda testme.gcno 