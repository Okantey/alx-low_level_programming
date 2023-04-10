#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the number of letters actually read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, let, w;
	char *text;

	text = malloc(letters);

	if (text == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
	{
		free(text);
		return (0);
	}

	let = read(file, text, letters);
	w = write(STDOUT_FILENO, text, let);

	close(file);
	free(text);

	return (w);
}

