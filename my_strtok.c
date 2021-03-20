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
    static int call = 1;		//static variable for contain function call
    static char *input = NULL;		//input pointer which will hold address after tokenization
    static char *str = NULL;		//temp pointer for store src string
    char *temp = NULL; 
    if(call == 1)			//execute this block only first function call
    {
        str = (char *)malloc(sizeof(char) * (strlen(src) + 1));	//memory allocation for temp
	memset(str,0,sizeof(char) * (strlen(src) + 1));
        strcpy(str,src);					//copying src string into temp
	temp = str;
    }

    if(temp == NULL)
    {
	temp = input;		//assign input address to temp
    }

    while(TRUE)
    {
	if(my_is_delim(*temp, delim))
	{
	    temp++;		//increment temp
	    continue;
	}

	if(*temp == '\0')
	{
	    free(str);		//freeing memory of str
	    return NULL;	//return NULL when we reach end of the string
	}

	break;
    }

    char *result = temp;
    while(TRUE)
    {
	if(*temp == '\0')
	{
	    input = temp;
	    return result;
	}

	if(my_is_delim(*temp, delim))
	{
	    *temp = '\0';
	    input = temp + 1;
	    return result;
	}

	temp++;
	call++;
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
    memset(ptr, 0, sizeof(char) * (strlen(src) + 1));
    if(ptr != NULL)
    {
	strcpy(ptr, src);		//copy source string into ptr
	char *token = my_strtok(ptr," ;:.,'-");	//function call of my_strtok

	while(token != NULL)
	{
	    printf("Token %d : %s\n",num, token);//printing tokenized string
	    token = my_strtok(NULL, " ;:.,'-");	//function call of my_strtok
	    num++;
	}

	printf("ptr, after print every token : %s\n", ptr);
    }
    else
    {
	printf("Insufficent memory........!!!!!");
    }

    free(ptr);		//memory deallocation of dest pointer
    ptr = NULL;

    return 0;
}
