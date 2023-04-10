#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to input string
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return (len);
}

/**
 * create_file - creates a file with the given filename and writes the given
 * text content to it
 * @filename: pointer to the filename string
 * @text_content: pointer to the text content string
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
    int fd, res;
    ssize_t len;

    if (!filename)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

    if (fd == -1)
        return (-1);

    if (text_content)
    {
        len = _strlen(text_content);
        res = write(fd, text_content, len);

        if (res == -1)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);

    return (1);
}

