/******* Implementation of strncat() function *******/


/*****************************************************
*	STANDARD HEADER FILES
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

/****************************************************
*	MACRO
****************************************************/
#define SIZE 200

/****************************************************
*	FUNCTION DECLARATION
****************************************************/
char * my_strncat(char * dest, const char * src, size_t n);
int my_strlen(const char *str);

/****************************************************
*	FUNCTION DEFINATION
*****************************************************
*
*	Function Name : my_strncat
*	Arguments     : char * dest (Destination String)
	                char * src  (Source String)
			int n       (No. of characters to be append)
*	Return Value  : char *      (char pointer of dest string)
****************************************************/
char * my_strncat(char * dest, const char * src, size_t n)
{
    int i = 0,
        j = 0;

    i = my_strlen(dest);	//calculating length of destination string

    for(j = 0; src[j] != '\0' && j < n; j++)
    {
        dest[i + j] = src[j];	//copying n characters of source string into end of destination string
    }
    dest[i + j] = '\0';		//add NULL character 

    return dest;		//return pointer of destination string
}


/****************************************************
*	Function Name : my_strlen
*	Arguments     : char * str (Input String)
*	Return Value  : int length (length of the Input String)
****************************************************/
int my_strlen(const char *str)
{
    int length = 0;		//variable for string length

    while(*(str + length) != '\0')	//running loop at the end of string
    {
        length++;		//incrementing length by 1
    }	

    return length;		//return total length of string
}

/***************************************************
*	MAIN FUNCTION
***************************************************/
int main()
{
    char src[SIZE];		//char array for source string
    char dest[SIZE];		//char array for destination string
    int n = 0;
    int len = 0;

    printf("Enter Source String      : ");
    fgets(src, sizeof(src), stdin);	//take source string from standard input
    len = my_strlen(src);
    src[len - 1] = '\0';		//adding NULL character at the end of source string

    printf("Enter Destination String : ");
    fgets(dest, sizeof(dest), stdin);	//take source string from standard input
    len = my_strlen(dest);
    dest[len - 1] = '\0';		//adding NULL character at the end of source string

    printf("Enter no. of charachers you need to copy : ");
    scanf("%d", &n);

    if(n < 0)
    {
	printf("No. of character to be append should be 0 or more than 0....!!!\n");
    }
    else
    {
	my_strncat(dest,src,n);	//function call of my_strncat
	printf("Destination String after strncat : %s\n", dest);
    }

    return 0;
}
