#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "skel2.h"

int main (int argc, char *argv[])
{
    /**************initials*****************/
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;
    char relation[] = "<>|&^";
    char para[] = "()";
    char bracket[] = "{}";
    char arrb[] = "[]";
    char subbuff[100];
    int count = 0;
    int paracount = 0;
    int arrcount = 0;
    int linecount = 0;
    /*************************************/

    /*******************arguments check***************/
    if (argc > 2)
    {
	printf("ERROR IN ARGUMENTS\n");
	exit(0);
    }

    /***********************************************/
    fp = fopen(argv[1],"r");


    if (fp == NULL)
    {
	printf("error while opening the file\n");
	exit(0);
    }


    /****************************************/
    while ((ch = fgetc(fp)) != EOF)
    {
	
	
	/*************check operators**********/
	
	for (i = 0; i < 6; ++i)
	{
	    if(ch == operators[i])
		printf("%c is arithmetic operator\n", ch);
	}

	/**************check realtional operators**********/
	for (i = 0; i < 5; ++i)
	{
	    if(ch == relation[i])
		printf("%c is relational operator\n", ch);
	}

	/***************check paranthesis***********/
	for (i = 0; i < 2; i++)
	{
	    if(ch == para[i])
	    {
		printf("%c is paranthesis\n", ch);
		paracount++;
	    }
	}

	/**************check brackets************/
	for (i = 0; i < 2; i++)
	{
	    if(ch == bracket[i])
	    {
		printf("%c is flowerbrackets\n", ch);
		count++;
	    }
	}

	/*****************************************/

	for (i = 0; i < 2; i++)
	{
	    if(ch == arrb[i])
	    {
		printf("%c is arraybrackets\n", ch);
		arrcount++;
	    }
	}


	/************store to buffer*************/
	if (isPunct(ch) || isalnum(ch) || isChar(ch))
        {
	    buffer[j++] = ch;

	}
	else if ((ch == ' ' || ch == '\n') && (j != 0))
	{
	    buffer[j] = '\0';
	    j = 0;

	    if (isKeyword(buffer) == 1)
		printf("%s is keyword\n", buffer);
	    else if(isstring(buffer) == 1)
		printf("%s is string\n", buffer);
	    else if(ischa(buffer) == 1)
		printf("%s is char\n", buffer);
	    else if(isAlpha(buffer) == 1)
		printf("%s is indentifier\n", buffer);
	    else if(isDigit(buffer) == 1)
		printf("%s is numerical constant\n", buffer);
	    else
	    {   system("clear");
		printf("%s is error\n", buffer);
		exit(0);
	    }

	}

    }

    /************************************************/
    

    if (count % 2 != 0)
    {
	system("clear");
	printf("{ is error\n");
    }
 
    if (arrcount % 2 != 0)
    {
	system("clear");
	printf("[ is error\n");
    }

     if (paracount % 2 != 0)
    {
	system("clear");
	printf("( is error\n");
    }

    
    
    fclose (fp); //file close

    return 0;
}
