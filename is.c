#include <stdio.h>
#include "skel2.h"
#include <string.h>
#include <ctype.h>

/***********check for keyword*************/
int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
	"do","double","else","enum","extern","float","for","goto",
	"if","int","long","register","return","short","signed",
	"sizeof","static","struct","switch","typedef","union",
	"unsigned","void","volatile","while"};
    int i, flag = 0;

    for(i = 0; i < 32; ++i)
    {
	if(strcmp(keywords[i], buffer) == 0)
	{
	    flag = 1;
	    break;
	}
    }

    return flag;
}

/*****************check alpha****************/
int isAlpha(char *buff)
{
    int i = 0, count = 0;
    int len;
    len = strlen(buff);
    //printf("len is %d\n", len);

    for (i = 0; buff[i] != '\0'; i++)
    {
	if(isalpha(buff[i]))
	    count++;

    }

    if (count == len)
    { 

	return 1;
    }
    else

    {
	return 0;
    }

}

/******************check for digit********************/
int isDigit(char *buff)
{
    int i = 0, count = 0;
    int len;
    len = strlen(buff);

    for (i = 0; buff[i] != '\0'; i++)
    {
	if(isdigit(buff[i]))
	    count++;
    }

    if (count == len)
    {
	return 1;
    }

    else
    {
	return 0;
    }
}
/*****this is about string check****/
int isstring(char *buff)
{
    int len;
    len = strlen(buff);
    //printf("---%c----\n", buff[0]);
    //printf("----%c----\n", buff[len - 1]);

    if (buff[0] == '"' && buff[len - 1] == '"')
    {
	return 1;
    }
    else
    {
	return 0;
    }
	     

    

}
/***********************************/

int isPunct(char ch)
{
    if(ch == '"')
	return 1;
    else
	return 0;
}
/*********************************/

int isChar(char ch)
{
    if (ch == '\'')
	return 1;
    else
	return 0;
}

/***********************************/
int ischa(char *buff)
{
    int len;
    len = strlen(buff);
    //printf("---%c----\n", buff[0]);
    //printf("----%c----\n", buff[len - 1]);

    if (buff[0] == '\'' && buff[len - 1] == '\'')
    {
	return 1;
    }
    else
    {
	return 0;
    }
	     

    

}

