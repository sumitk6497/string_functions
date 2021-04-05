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
    char ch;
    int i = 0;
    int len = 0, count = 0;

    printf("Enter Source String : ");
    fgets(src, sizeof(src), stdin);	//take source string from standard input
    len = strlen(src);
    src[len - 1] = '\0';		//adding NULL character at the end of source string
    len = strlen(src);

    printf("Enter a characher you need to search : ");
    scanf("%c", &ch);

    for(i = 0; i <= len; i++)
    {
        if(ch == src[i])
	    count++;
    }

    printf("\nCharacter '%c' occured '%d' times in '%s'.......!!!!!!\n", ch, count, src);

    return 0;
}
