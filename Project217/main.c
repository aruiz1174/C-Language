/*
 * main.c
 *
 *  Created on: May 2, 2020
 *      Author: Anibal Ruiz, N00866307
 *      Help From: Tony Ruiz
 *                 GeeskforGeeks
 *                 The C Programming by Brian Kernighan
 *
 * -I built this program on Mac, and it was tested on a Window machine.
 *
 * **** I am aiming for a grade of 90. ****
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

int main(int argc, char *argv[])
{
	//i was just testing the enqueue function

	/**
	node *queue = NULL;

	char* a = "hello";
	char* b = "world";
	char* c = "hello";
	char* d = "Tony";

	queue = enqueue(queue, a);
	queue = enqueue(queue, b);
	queue = enqueue(queue, c);
	queue = enqueue(queue, d);

	printlist(queue);

    queue = deleteword(queue, "hello");
	printf("\n\n");

	printlist(queue);

    */


	//declare wot list, one queue and one stack, and initialized them to NULL
	node *queue = NULL;
	node *stack = NULL;

	//declrar a file pointer
	FILE *fp;

	//name of the file
	char *fileName = NULL;

	//You may assume a line will be no longer than 80 characters.
	char data[81];

	//variables needed to be able to code my program
	int numlines = 0;
	int counter = 0;

	//I primary use the forr loop to find where the user will write the -f and -n option.
	for(int i = 0; i < argc; i++)
	{
		if(!mystrcmp(argv[1], "-h"))
		{
			printf("Use this function as: %s -f file.txt\n", argv[0]);
			return 0;
		}

		if(!mystrcmp(argv[i], "-f"))
		{
			fileName = argv[i + 1];
		}

		if(!mystrcmp(argv[i], "-n"))
		{
			// if the user don,t put the number of lines after the -n option, then error.
			if(argv[i + 1] == NULL)
			{
				printf("Error: Use function like this: %s -n 10 -f file1.txt\n", argv[0]);
				exit(1);

			}

			else
			{
				//if the number of lines the user writes is 0 or negative, error
				//also the number of lines numLines is being saved
				if((numlines = myAtoi(argv[i + 1])) <= 0 )
				{
					printf("Error: Use function like this: %s -n 10 -f file1.txt", argv[0]);
					exit(1);
				}
			}

		}
	}

	//if the fileNme is true
	if(fileName)
	{
		//open the file and read
		fp = fopen(fileName, "r");

		if(fp == NULL)
		{
			perror("Error");
		}

	}
	else
	{
		fp = stdin;
	}

	//if the user don.t use the option -n, there's no reason to rpint any number of lines, so you print the whole file or until EOF.
	if(numlines == 0)
	{
		//reads a limited number of characters from a given file stream source into an array of characters.
		while(fgets(data, 81, fp))
		{
			char *space = "\r\n"; //var for the spaes between the wprds

			//this function split str into tokens, which are sequences of contiguous
			//characters separated by any of the characters that are part of delimiters.
			char *lines = strtok(data, space);


			while(lines != NULL)
			{
				//enqueue the words in the file
				queue = enqueue(queue, lines);

				//push the words in the file
				stack = push(stack, lines);

				//split the str into tokens again to start with a new word
				lines = strtok(NULL, space);
				//printf("HEYY");
			}
		}
	}

	//if the option -n is used,
	if(numlines > 0)
	{

		//printf("num of lines: %d", numlines);
		//then print until counter is less or equal than numLines, increase counter each time.
		while(fgets(data, 81, fp))
		{

			//if newSpace was initialized like the space variable above, char *space = "\r\n"; ,  the -n 2 option for example, would print two words and not two lines. .
			//it gave a lot of problems, I thought it was my code that did not work but then I tried to initialized to ""; and it worked. Not sure why.
			char *newSpace = "";

			char *line2 = strtok(data, newSpace);

			while((line2 != NULL) && (counter < numlines))
			{
				//quenque the words of the file
				queue = enqueue(queue, line2);

				//push the wordsof the file
				stack = push(stack, line2);

				////split the str into tokens again to start with a new word
				line2 = strtok(NULL, newSpace);

				//printf("\nOne Completed\n");
				//counter++;
			}
			//printf("\nOne Completed\n");
			counter++;


		}
	}

	//print the queue
	printf("Print the Queue: \n");
	printlist(queue);

	printf("\n\n");

	//print the stack
	printf("Print the Stack: \n");
	printlist(stack);

	printf("\n\n");


	//delete both listband free the memory (done in the functions)
	queue = deletelist(queue);
	stack = deletelist(stack);

	//if the lists were successfully deleted, then it wont't print anything
	printlist(queue);
	printlist(stack);


	return 0;
}




