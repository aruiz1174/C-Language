/*
 * lab1.c
 *
 *  Created on: Feb 6, 2020
 *      Author: anibal ruiz
 */

#include <stdio.h>
#include "lab1.h"
#define MAXLINE 1000


/**
 * read the each character in the array.
 */
int krgetline(char s[], int lim)
{
    char c; int i;
    for (i = 0; i < lim-1 && (c = getchar()) != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/**
 * compare two arrays of characters and return 0 is they equal,
 * otherwise return a negative if it is less or positive if it is greater.
 */
int mystrcmp(char s[], char t[])
{
    int i = 0;
    for(; t[i] == s[i]; i++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/**
 * give the length of the array.
 */
int mystrlen(char s[])
{
	int i = 0;
	for(; s[i] != '\0'; i++)
		;
	return i;
}

