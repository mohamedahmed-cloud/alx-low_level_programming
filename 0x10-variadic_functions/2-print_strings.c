#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - function that prints numbers, followed by a new line.
 * @separator: our seperator.
 * @...: all arguments pass.
 * @n: no.of elements
 * Return: return the element.
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
va_list ptr;
unsigned int i = 0;
char *s;
va_start(ptr, n);

for (i = 0; i < n; i++)
{
s = va_arg(ptr, char *);
if (s == NULL)
printf("(nil)");
else
printf("%s", s);
if (i + 1 < n && separator != NULL)
{
printf("%s", separator);
}

}
printf("\n");
va_end(ptr);
}
