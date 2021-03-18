/******* Implementation of strlen() function *******/


/*****************************************************
*	STANDARD HEADER FILES
*****************************************************/
#include <stdio.h>
#include <string.h>

/****************************************************
*	MACRO
****************************************************/
#define SIZE 200

/****************************************************
*	FUNCTION DECLARATION
****************************************************/
size_t my_strlen(const char *str);

/****************************************************
*	FUNCTION DEFINATION
*****************************************************
*	Function Name : my_strlen
*	Arguments     : char * str (Input String)
*	Return Value  : int length (length of the Input String)
****************************************************/
size_t my_strlen(const char *str)
{
    size_t length = 0;		//variable for string length

    while(*(str) != '\0')	//running loop at the end of string
    {
        length++;		//incrementing length by 1
	str++;
    }	

    return length;		//return total length of string
}

/***************************************************
*	MAIN FUNCTION
***************************************************/
int main()
{
    char src[SIZE];		//char array for source string
    char src1[SIZE];		//char array for source string
    size_t len = 0;

    printf("Enter Source String      : ");
    fgets(src, sizeof(src), stdin);	//take source string from standard input
    len = my_strlen(src);
    src[len - 1] = '\0';		//adding NULL character at the end of source string

    len = my_strlen(src);
    printf("String length of %s is : %ld\n", src, len);
    printf("String length of %s is : %ld\n", src, strlen(src));

    return 0;
}
