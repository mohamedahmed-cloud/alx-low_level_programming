#include "main.h"
#include <string.h>
/**
 * rev_string - reverse string.
 * @s: the string to print.
*/
void rev_string(char *s)
{
	int i = 0;
	int n = strlen(s);
	int x = n / 2;

	for (i = 0; i < x; i++)
	{
		char c = s[i];

		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
}
