/*
 * main.c
 *
 *  Created on: Apr 24, 2020
 *      Author: Anibal Ruiz
 */

#include <stdlib.h>
#include <stdio.h>
#include "lab4.h"
//#include <string.h>

int main(int argc, char* argv[])
{
	char* filename = NULL; // filename is used to store the name of the file provided in the options.
	int p; //We use p to store if we want the smallest or largest string (p is 0 for smallest string, while it's 1 for largest string)

	/**
	 * I have two main if else statements, one to check if I have 2 or 4 arguments,
	 * otherwise the options are not valid.
	 * To avoid hardcoding, the name of the program in our code I simply pass to the incorrectUsage
	 * function argv[0] which is the name of the program.
	 */

	//If I have 2 arguments, then the second
	 //* must be either "-l" or "-s".
	if(argc == 2)
	{
		if(mystrcmp(argv[1], "-s") == 0)
		{
			p = 0;
		}
		else if(mystrcmp(argv[1], "-l") == 0)
		{
			p = 1;
		}
		else
		{
			incorrectUsage(argv[0]);
			return -1;
		}
	}

	//If I have 4 arguments then it must be one of
	// * these: "-s, -f, filename", "-l -f filename", "-f filename -s" or "-f filename -l".
	else if (argc == 4)
	{
		if(mystrcmp(argv[1], "-s") == 0)
		{
			p = 0;
			if(mystrcmp(argv[2], "-f") != 0)
			{
				incorrectUsage(argv[0]);
				return -1;
			}
			filename = argv[3];
		}
		else if(mystrcmp(argv[1], "-l") == 0)
		{
			p = 1;
			if(mystrcmp(argv[2], "-f") != 0)
			{
				incorrectUsage(argv[0]);
				return -1;
			}
			filename = argv[3];
		}
		else if(mystrcmp(argv[1], "-f") == 0)
		{
			filename = argv[2];
			if(mystrcmp(argv[3], "-s") == 0)
			{
				p = 0;
			}
			else if(mystrcmp(argv[3], "-l") == 0)
			{
				p = 1;
			}
			else
			{
				incorrectUsage(argv[0]);
				return -1;
			}
		}
		else
		{
			incorrectUsage(argv[0]);
			return -1;
		}
	}
	else
	{
		incorrectUsage(argv[0]);
		return -1;
	}

	int i = 0, n;
	FILE *fptr;

	if(filename != '\0')
	{
		fptr = fopen(filename, "r");
	}
	else
		fptr = stdin;

	/**
	 * EOF indicates "end of file". A newline (which is what happens when you
	 * press enter) isn't the end of a file, it's the end of a line, so a newline doesn't terminate this loop.
	 *
	 */

	char **dynamic_array;

	/**
	 * read the file line by line using fgets and reallocating the dynamic array
	 *  using the realloc function
	 */
	dynamic_array = (char**) malloc(sizeof(char*));
	dynamic_array[i] = (char*) malloc(1000 * sizeof(char));

	//When we reach the end of file EOF character the fgets function returns
	//a NULL pointer, the while cycle then ends.
	while(fgets(dynamic_array[i], 1000, fptr) != '\0')
	{
		i++;
		dynamic_array = (char**) realloc(dynamic_array, (i+1)*sizeof(char*));
		dynamic_array[i] = (char*) malloc(1000 * sizeof(char));
	}


	/**
	 * find the longest or shortest string in those stored in
	 * dynamic array. We first of all store the total number of strings in n,
	 * then a variables max to store the maximum or minimum length,
	 * pos to store the position of the maximum or minimum string, currentLen to store
	 * the length of the current string.
	 */
	n = i + 1;
	i = 0;
	int max, pos = 0, currentLen;

	if(p == 1)
	{
		max = 0;
		for(i = 0; i < n; i++)
		{
			currentLen = mystrlen(dynamic_array[i]);
			if(currentLen > max)
			{
				max = currentLen;
				pos = i;
			}
		}
	}
	else
	{
		max = mystrlen(dynamic_array[i]);

		for(i = 0; i < n - 1; i++)
		{
			currentLen = mystrlen(dynamic_array[i]);
			if(currentLen < max)
			{
				max = currentLen;
				pos = i;
			}
		}
	}

	printf("%s\n", dynamic_array[pos]);
	fclose(fptr);
	return 0;
}
