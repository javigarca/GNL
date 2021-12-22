#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{

char *texto;
char *linea;
int fd;

texto = "textos/pruebas.txt";
fd = open(texto, O_RDONLY);
linea=get_next_line(fd);

if (fd < 0)
{
	printf("%s\n", strerror(errno));
	write (2, "FAIL", 4);
}

//while (linea)
//	{
		printf("%s", linea);
		linea = get_next_line(fd);
		printf("%s", linea);
		linea = get_next_line(fd);
		linea = get_next_line(fd);
		printf("%s", linea);
		linea = get_next_line(fd);
		printf("%s", linea);
		linea = get_next_line(fd);
		printf("%s", linea);
		linea = get_next_line(fd);
		printf("%s", linea);
		linea = get_next_line(fd);
		printf("%s", linea);
		linea = get_next_line(fd);
//	}
fd = close(fd);
return (0);
}

