/*
 * list.h
 *
 *  Created on: May 2, 2020
 *      Author: anibalruiz
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef LIST_H_
#define LIST_H_

struct node
{
	struct node *next;
	char *data;
};
typedef struct node node;

node* enqueue(node *head, char *s);
node* push(node *head, char *s);
void printlist(node *head);
node* deletelist(node *head);
node* deleteworld(node *head, char *s);

int mystrcmp(char *s, char *t);
int myAtoi(char* s);



#endif /* LIST_H_ */
