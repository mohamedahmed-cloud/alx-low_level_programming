#include "main.h"
/**
* print_alphabet - print string
*
* Return: Always 0
*/
void print_alphabet(void)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 97; j < 123; j++)
		_putchar(j);
		_putchar('\n');
	} }
