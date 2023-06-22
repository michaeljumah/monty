#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * getline - gets the next line of input from standard input
 * @lineptr: pointer to buffer
 * @n: number
 * @stream: file path
 *
 * Return: pos
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;

	if (!lineptr || !stream)
		return (-1);
	if (*n == 0)
	{
		*n = 128;
	}
	*lineptr = (char *) malloc(*n);
	if (!*lineptr)
	{
		return (-1);
	}
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF || c == '\n')
		{
			(*lineptr)[pos] = '\0';
			if (pos == 0 && c == EOF)
			{
				return (-1);
			}
			else
			{
				return (pos);
			}
		}
		if (pos >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (!*lineptr)
			{
				return (-1);
			}
		}
		(*lineptr)[pos++] = c;
	}
}
