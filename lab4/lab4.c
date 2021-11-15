/*
 * lab4.c
 *
 *  Created on: Apr 25, 2020
 *      Author: anibalruiz
 */

#include <stdio.h>
#include "lab4.h"

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

void incorrectUsage(char* program)
{
	printf("%s\n", program);
	printf("Incorrect usage. Use this program as such:\n");
	printf("%s -f name_of_file -s or -l\n", program);
	printf("%s -s or -l\n", program);
	// return;
}

/**
 * give the length of the array.
 */
int mystrlen(char *s)
{
	int i = 0;
	for(; *s != '\0'; i++, s++)
		;
	return i;
}




