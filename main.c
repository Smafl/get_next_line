#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER 99

int main(void)
{
	int fd;
	// char text[BUFFER + 1];
	char *text;
	int read_size;

	fd = open("text.txt", O_RDONLY);
	text = malloc(sizeof(char) * 100);
	read_size = read(fd, text, BUFFER);
	printf("fd %d\n read size %d\n", fd, read_size);
	while (*text)
	{
		write(1, text, 1);
		text++;
	}
	free(text);
	// system("leaks a.out");
	return (0);
}
