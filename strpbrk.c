#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "github";
	
	char s2[] = "app";
	char s3[] = "coding";
	
	char* r, *t;

	// Checks for matching character
	// no match found
	r = strpbrk(s1, s2);
	if (r != 0)
		printf("First matching character: %c\n", *r);
	else
		printf("Character not found\n");

	// Checks for matching character
	// first match found at "g"
	t = strpbrk(s1, s3);
	if (t != 0)
		printf("First matching character: %c\n", *t);
	else
		printf("Character not found\n");

	return 0;
}

