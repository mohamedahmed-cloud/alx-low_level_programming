/**
* _isalpha - find if the char is lower or upper.
*
*@c: is an integer value passed from main function.
* Return: Always 0
*
*/
int _isalpha(int c)
{
	if ((c >= 97 && c < 123) || (c>=65 && c<91))
	return (1);
	return (0); }
