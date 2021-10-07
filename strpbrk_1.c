#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "victory";

	char p1[] = "a23";
	char p2[] = "i22";
	char* r, *t;

	// Use of strpbrk()
	r = strpbrk(s1, p1);
	t = strpbrk(s1, p2);

	// Checks if player 1 has won lottery
	if (r != 0)
		printf("P1 : Congrats u have won\n");
	else
		printf("P1 : Better luck next time\n");


	// Checks if player 2 has won lottery
	if (t != 0)
		printf("P2 : Congrats u have won\n");
	else
		printf("P2 : Better luck next time\n");

	return 0;
}

