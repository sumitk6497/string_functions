/******* Implementation of strncpy() ***************/


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

/****************************************************
*	FUNCTION DECLARATION
****************************************************/
char * my_strncpy(char * dest, const char * src, size_t n);


/****************************************************
*	FUNCTION DEFINATION
*
*	Function Name : my_strncpy
*	Arguments     : char * dest (Destination String)
	                char * src  (Source String)
			int n       (No. of characters to be copy)
*	Return Value  : NULL
****************************************************/
char * my_strncpy(char * dest, const char * src, size_t n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
	    *dest = *src;	//copying source string into destination string
	    src++;		//increment source pointer
	    dest++;		//increment destination pointer
    }    
    *dest = '\0';		//add NULL character
    return dest;
}

/***************************************************
*	MAIN FUNCTION
***************************************************/
int main()
{
    char src[SIZE];		//char array for source string
    char *dest = NULL;		//char pointer for dest string
    int n = 0;
    int len = 0;

    printf("Enter Source String : ");
    fgets(src, sizeof(src), stdin);	//take source string from standard input
    len = strlen(src);
    src[len - 1] = '\0';		//adding NULL character at the end of source string

    printf("Enter no. of charachers you need to copy : ");
    scanf("%d", &n);

    if(n < 1)
    {
	printf("No. of character to be copy should be more than 0....!!!\n");
    }
    else
    {
	dest = (char *)malloc(sizeof(char) * (n + 1));	//memory allocation of dest string
	if(dest != NULL)
	{
	    printf("\nSource String      : %s", src);
	    my_strncpy(dest,src,n);				//function call of my_strncpy
	    printf("\nDestination String : %s\n", dest);
	}
	else
	{
	    printf("Insufficent memory........!!!!!");
	}

	free(dest);		//memory deallocation of dest pointer
	dest = NULL;
    }

    return 0;
}
