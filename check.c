#include <stdio.h>
#include "skel.h"
#include <string.h>

char *reserved_key1[37] = {"const", "volatile", "extern", "auto", "register", "static", "signed", "unsigned", "short", "long", "double", "char", "int", "float", "struct", "union", "enum", "void", "typedef", "FILE","goto", "return", "continue", "break", "if", "else", "for", "while", "do", "switch", "case", "default", "sizeof", "EOF", "stderr", "stdout", "stdin"};



int check_keyword(char *buff)
{

    int idx = 0, count = 0;
    
     while (*reserved_key1[idx] != '\0')   
    {
	if (strcmp(reserved_key1[idx++] , buff) == 0)
	    return 1;
        else
	 {
             count++;
	 }
        if (count == 36)
	{
          goto outside;
	}	  
    }
outside:
     return 0;

   
}


int check_symbol(char *buff)
{

    if (buff[0] == '{')
    {
	printf("%s - Leftflowerbrace\n", buff);
    }

    if (buff[0] == '}')
    {
	printf("%s - Rightflowerbrace\n", buff);
    }
    if (buff[0] == '(')
    {
        printf("%s - Leftcbrace\n", buff);
    }
    if (buff[0] == ')')
    {
	printf("%s - Rightbrace\n", buff);
    }

}

