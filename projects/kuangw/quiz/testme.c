#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // using a rondom function
    // 33 for all char that we can use all lower case with special sectioning chars
    // such as (), {}, []
    char bank[] = "abcdefghijklmnopqrstuvwxyz()[]{} ";
    return bank[rand()%33];
}

char *inputString()
{ 
    // this is the shortened version of the bank string to decrease asssessment time
    char bank[] = "restabcdefg";
    // size of 6 including the null termniator
    char *string = malloc(sizeof(char)*6);
    int i;

    // randomly added 5 chars to the return string chosing from char bank: bank
    for ( i = 0; i < 5; i++){
        string[i] = bank[rand()%11];
    }
    // this has to have null terminator at the end so the 6th index is always null terminator
    string[5] = '\0';

    return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
