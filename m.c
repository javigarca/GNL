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

linea = get_next_line(fd);
printf("(%s)", linea);
printf("(%s)", get_next_line(fd));
printf("(%s)", get_next_line(fd));
//printf("%s", get_next_line(fd));
printf("%s", get_next_line(fd));
fd = close(fd);
return (0);
}

