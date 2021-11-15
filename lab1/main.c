/*
 *
 * main.c
 *
 *  Created on: Feb 11, 2020
 *      Author: Anibal Ruiz
 */

#include <stdio.h>
#include "lab1.h"
#define MAXLINE 1000

/**
 * Compare a given string with an input's string.
 */
int main()
{
    char testString[] = "abc";
    char userInput[MAXLINE];

    int len;
    int compare = -1;
    while(compare != 0)
    {
        printf("Please enter abc: ");
        krgetline(userInput, MAXLINE);
        len = mystrlen(userInput);
        //compare = mystrcmp(testString, userInput);

        //HELP FROM TONY RUIZ in the IF STATEMENT.
        if (len > 0 && userInput[len-1] == '\n')
        {
        	//set the \n euqal to null
            userInput[--len] = '\0';

        }
        compare = mystrcmp(userInput, testString);


    }

    return 0;
}
