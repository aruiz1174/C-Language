/*
 * lab3.c
 *
 *  Created on: Mar 28, 2020
 *      Author: Anibal Ruiz, N00866307
 * Help from: GeeksforGeeks, The C Programming Language by Brian Kernighan, and (Tony Ruiz).
 */


#include <stdio.h>
#include "lab3.h"

/**
 * reverse the strings
 */
void reverse(int n, int i, char *s[])
{
	 for(i = n - 1; i > - 1; i--)
	    {
	        printf("%s ", s[i]); //start prin1ting the input starting from the last word, we are reversint now.
	    }
}

/**
 * compare two pointers of characters and return 0 is they equal,
 * otherwise return a negative if it is less or positive if it is greater.
 */

int mystrcmp(char *s, char *t)
{
    for(; *t == *s; s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}

/**
 * The myAtoi function skips all white-space characters at the beginning of the string,
 * converts the subsequent characters as part of the number,
 * and then stops when it encounters the first character that isn't a number.
 */
int myAtoi(char* s)
{
    int res = 0; // Initialize result

    // Iterate through all characters of input string and
    // update result
    for (; *s != '\0'; ++s)
        res = res * 10 + *s - '0';

    // return result.
    return res;
}
