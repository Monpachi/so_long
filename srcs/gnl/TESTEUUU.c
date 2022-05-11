#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;
	char	*Hugo;

	fd = open("JeanYves.txt", O_RDONLY);
	Hugo = get_next_line(fd);
	printf("%s\n", Hugo);
	free(Hugo);
	close (fd);
	return (0);
}
