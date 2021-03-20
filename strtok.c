/************ Usage of strtok() function ************/


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
	char *token = strtok(ptr," ;:.,'-");	//function call of my_strtok

	while(token != NULL)
	{
	    printf("Token %d : %s\n",num, token);//printing tokenized string
	    token = strtok(NULL, " ;:.,'-");	//function call of my_strtok
	    num++;
	}
    }
    else
    {
	printf("Insufficent memory........!!!!!");
    }

    free(ptr);		//memory deallocation of ptr pointer
    ptr = NULL;

    return 0;
}
