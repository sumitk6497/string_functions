/************ Usage of strncpy() function ************/


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
    char dest[SIZE];		//char array for dest string
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
	    printf("\nSource String      : %s", src);
	    strncpy(dest,src,n);				
	    printf("\nDestination String : %s\n", dest);
    }

    return 0;
}
