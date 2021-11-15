/*
 * main.c
 *
 *  Created on: Mar 29, 2020
 *      Author: Anibal Ruiz, N00866307
 * Help from: GeeksforGeeks, The C Programming Language by Brian Kernighan, and (Tony Ruiz).
 */

#include <stdio.h>
#include "lab3.h"

int main(int argc, char *argv[])
{
    int n = myAtoi(argv[2]);//Transform the third parameter, or the character after -n who's the number

    if(mystrcmp(argv[1], "-n") != 0 || argc - 3 < n) //don.t include the name of the program, -n and the actual number (-3)
    {
    	++(*argv); //increment once, then in the printf increment once again to print the name of the program without the "./" (for mac) in the error message.
        printf("Incorrect usage. Use this program as such:\n");
        printf("ex: %s -n 2 hello world\n", ++(*argv)); //*argv is the name of the program
        return 0;
    }

    char *t[n];
    int i = 0;

    for(; i < n && 3 + i < argc; i++) //spot 3 is pointing to the "first" string after the value of -n.
    {
        t[i] = argv[3 + i]; //save the words to be reversed in a different pointer array.
    }

    reverse(n, i, t); //reverse the strings

    printf("\n");


	/**
    char* arr[] = { "Hello", "World", "1", "2" };
    int n = sizeof(arr) / sizeof(arr[0]);

    PrintArray(arr, n);

    printf("\n");

    ReverseArray(arr, n);

    PrintArray(arr, n);
    */

    return 0;
}
