#include <stdio.h>
#include "shell.h"

/**
 * factorial - calculates the factorial of a given integer n
 * @n: integer argument for the program
 *
 * Return: factorial of n, or -1 if n is negative
 */
int factorial(int n)
{
	int result = 1;

	if (n < 0)
	{
		return (-1);
	}

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return (result);
}

