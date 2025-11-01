#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: input string
 *
 * Return: the converted integer, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int result = 0;

	/* scan until we hit digits; count all preceding '-' to flip sign */
	while (s[i] != '\0')
	{
		if (s[i] == '-' && !started)
			sign = -sign;
		else if (s[i] == '+' && !started)
			; /* ignore */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (started)
		{
			break;
		}
		i++;
	}
	return (result * sign);
}
