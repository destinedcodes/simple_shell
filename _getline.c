#include "shell.h"

/**
 * _getline - gets string from statndard input and stores in a buffer
 * @line: buffer for the string to be stored
 *
 * Return: number of characters read, if errror returns -1;
 */
ssize_t _getline(char **line)
{
	char *buf = (char *)malloc(8096);
	ssize_t n = 0;

	while ((read(0, &buf[n], 1)) > 0 && (buf[n] != '\n'))
		n++;

	if (n != 0)
	{
		*line = malloc(sizeof(char) * (n + 1));
		buf[n] = '\0';
		strcpy(*line, buf);
		free(buf);
		return (n);
	}
	else
	{
		free(buf);
		if (isatty(0))
			_fprintf(1, "\n");
		exit(status);
	}
}
