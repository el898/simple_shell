#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
/**
 * main - Entry point for simple shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char buf[BUFSIZE];
	while (1)
	{
	printf("simple_shell> ");
		if (fgets(buf, BUFSIZE, stdin) == NULL)
		{
			break;
		}
		buf[strcspn(buf, "\n")] = 0;

		if (execvp(buf, (char *[])
					{buf, NULL}) == -1)
		{
			perror("execvp");

		}
	}
	return (0);
}
