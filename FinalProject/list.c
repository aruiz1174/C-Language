/*
 * list.c
 *
 *  Created on: May 3, 2020
 *      Author: Anibal Ruiz, N00866307
 *
 *      Help from: GeeksForGeeks
 *                 Tony Ruiz
 *                 The C Programming c by Brian Kernighan
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

/**
 * In this function, we use a linked list to enqueue data into the list. for  of this project
 * the rear or tail is not used. In a queue function, the new node is placed after the node already existed.
 * Head never changes, only if the list is null.
 * i decided to return the node added for easier coding in main.
 */
node* enqueue(struct node *head, char *s)
{
	//check if head is null, if it is, allocate memory
	if(head == NULL)
	{
		//allocate memory for the head
		node* head = calloc(1, sizeof(node));

		if(head == NULL)
		{
			fprintf(stderr, "Not enough memory \n");
			exit(1);
		}

		//set the data for the word
		head->data = strdup(s);

		if(head->data==NULL)
		{
			fprintf(stderr, "Not enough memory \n");
			exit(1);
		}
		return head;
	}
	else
	{
		/* 1. allocate node */
		node* newNode = calloc(1, sizeof(node));

		if(newNode == NULL)
		{
			fprintf(stderr, "Not enough memory \n");
			exit(1);

		}

		/**
		the strdup() function returns a pointer to the duplicated
	    string.  It returns NULL if insufficient memory was available, with
		errno set to indicate the cause of the error.
		 */
		newNode->data = strdup(s);

		if(newNode->data ==NULL)
		{
			fprintf(stderr, "Not enough memory \n");
			exit(1);
		}

		node* trav = head;
		//this will traverse until next is null

		while(trav->next != NULL)
			trav = trav->next;

		//puts new node in the next one
		trav->next = newNode;

		return head;
	}
}

/*
 * in this function, we push using a inked list in a list. the data added always has to be in head.
 * So; the first data added, the last will be deleted.
 * I decided to return the new node added for easier coding in main.
 */
node* push(struct node *head, char *s)
{

	/* 1. allocate node */
	node* newNode = calloc(1,sizeof(node));

	/**
	the strdup() function returns a pointer to the duplicated
	string.  It returns NULL if insufficient memory was available, with
	errno set to indicate the cause of the error.
	 */
	newNode->data = strdup(s);

	if(newNode ->data == NULL)
	{
		fprintf(stderr, "Not enough memory \n");
		exit(1);
	}
	/* 3. Make next of new node as head */
	newNode->next = head;
	/* 4. move the head to point to the new node */
	head = newNode;

	return newNode;
}


/**
 * Print the linked list. No return anything, we just want to print the list.
 */
void printlist(struct node *head)
{
	int i = 1;
	//no need for trav
	while(head != NULL)
	{
		printf("(%d)%s ", i, head->data);
		head = head->next;

		if(head != NULL)
		{
			printf("\n");
		}
		i++;
	}
}
/**
 * delete the list. Memory have been allocating, so when you delete the list
 * you have to free the space. return the node delete, that will be NULL at the end of thelist.
 * just to have a reference. If I don't return anything, in Main my deletelist does not work properly.
 */
node* deletelist(struct node *head)
{
	node* delete = head;

	while(delete != NULL)
	{
		head = head->next;
		free(delete->data);
		free(delete);
		delete = head;
	}
	return delete;

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

/**

node* deleteworld(struct node *head, char *s)
{
	//start from the first link
	struct node* current = head;

	struct node* previous = NULL;

	//first special case
	//if list is empty
	if(head == NULL)
	{
		return NULL;

	}

	//traverse the lists
	while(current != NULL)
	{

		//look fot the world

		while(mystrcmp(current->data ,s) != 0)
		{
			//if it is last node, or not found
			if(current->next == NULL)
			{
				return NULL;

			}
			else
			{
				//store reference to current link
				previous = current;

				//move to next link
				current = current->next;

			}

		}

		//another special case, change head if there is somenthing to delete
		if(current == head)
		{

			//change first to point to next link
			head = head->next;

		}

		else
		{
			//bypass the current link
			previous->next = current->next;

		}

		current = current->next;

	}

	while(mystrcmp(current->data , s) != 0)
	{

		//if it is last node
		if(current->next == NULL)
		{

			return NULL;

		}

		else
		{

			//store reference to current link
			previous = current;

			//move to next link
			current = current->next;

		}

	}

	//found a match, update the link
	if(current == head)
	{

		//change first to point to next link

		head = head->next;

	}

	else
	{
		//bypass the current link

		previous->next = current->next;

	}

	return current;

}

*/


