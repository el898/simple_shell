#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - reads a file and writes its contents to stdout
 * @argc: number of arguments passed to the program
 * @argv: array of strings containing the arguments
 *
 * Return: 0 on success, 1 on failure
 */
	int main(int argc, char *argv[])
	{
		int fd, nread;
		char buffer[BUFFER_SIZE];
		char *token, *saveptr;

		if (argc != 2)
		{
			fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
			exit(EXIT_FAILURE);
		}

		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}

		while ((nread = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			token = strtok_r(buffer, " \n", &saveptr);
			while (token != NULL)
			{
				write(STDOUT_FILENO, token, strlen(token));
				write(STDOUT_FILENO, " ", 1);
				token = strtok_r(NULL, " \n", &saveptr);
			}
		}

	if (nread == -1)
	{
		perror("read");
 		exit(EXIT_FAILURE);
	}

	if (close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
	}

