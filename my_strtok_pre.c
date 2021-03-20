/******* Implementatiion of strtok() function ********/


/*****************************************************
*	STANDARD HEADER FILES
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************
*	MACRO
****************************************************/
#define SIZE 200
#define TRUE 1
#define FALSE 0

/****************************************************
*	FUNCTION DECLARATION
****************************************************/
char * my_strtok(char * src, const char * delim);
int my_is_delim(char src_c, const char * delim);

/****************************************************
*	FUNCTION DEFINATION
*
*	Function Name : my_is_delim
*	Arguments     : char * src          (Source String)
	                const char * delim  (Delimeter String)
*	Return Value  : TRUE if delimeter found
****************************************************/
int my_is_delim(char src_c, const char * delim)
{
    while(*delim != '\0')
    {
	if(src_c == *delim)
	  return TRUE;
	delim++;
    }
    return FALSE;
}

/****************************************************
*	Function Name : my_strtok
*	Arguments     : char * src          (Source String)
	                const char * delim  (Delimeter String)
*	Return Value  : char *
****************************************************/
char * my_strtok(char * src, const char * delim)
{
    static char *input = NULL; 

    if(src == NULL)
    {
	src = input;
    }

    while(TRUE)
    {
	if(my_is_delim(*src, delim))
	{
	    src++;
	    continue;
	}

	if(*src == '\0')
	{
	    return NULL; // we've reached the end of the string
	}

	break;
    }

    char *result = src;
    while(TRUE)
    {
	if(*src == '\0')
	{
	    input = src; // next exec will return NULL
	    return result;
	}

	if(my_is_delim(*src, delim))
	{
	    *src = '\0';
	    input = src + 1;
	    return result;
	}

	src++;
    }
}
/***************************************************
*	MAIN FUNCTION
***************************************************/
int main()
{
    char src[SIZE];		//char array for source string
    int len = 0;
    int num = 1;

    printf("Enter Source String : ");
    fgets(src, sizeof(src), stdin);	//take source string from standard input
    len = strlen(src);
    src[len-1] = '\0';			//adding NULL character at the end of source string

    char *ptr = (char *)malloc(sizeof(char) * (strlen(src) + 1));	//memory allocation for ptr
    if(ptr != NULL)
    {
	strcpy(ptr, src);		//copy srource string into ptr
	char *token = my_strtok(ptr," ;:.,'-");	//function call of my_strtok

	while(token != NULL)
	{
	    printf("Token %d : %s\n",num, token);//printing tokenized string
	    token = my_strtok(NULL, " ;:.,'-");	//function call of my_strtok
	    num++;
	}
    }
    else
    {
	printf("Insufficent memory........!!!!!");
    }

    free(ptr);		//memory deallocation of dest pointer
    ptr = NULL;

    return 0;
}
