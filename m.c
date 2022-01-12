#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{

char *texto;
int fd;

texto = "textos/2pruebas.txt";
fd = open(texto, O_RDONLY);
if (fd < 0)
{
	printf("%s\n", strerror(errno));
	write (2, "FAIL", 4);
}

printf("%s", get_next_line(fd));
printf("%s", get_next_line(fd));
printf("%s", get_next_line(fd));
printf("%s", get_next_line(fd));
printf("%s", get_next_line(fd));
//printf("%s", get_next_line(fd));
//printf("%s", get_next_line(fd));
fd = close(fd);
return (0);
}

