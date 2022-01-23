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
int cont;

//texto = "textos/4pruebas.txt";
//texto = "textos/brouette.txt";
//texto = "textos/linew.txt";
//texto = "textos/twochar.txt";
texto = "textos/b.txt";
//texto = "textos/oneline.txt";
//texto = "textos/pizarra1.txt";
//texto = "textos/41_no_nl";
fd = open(texto, O_RDONLY);
if (fd < 0)
{
	printf("%s\n", strerror(errno));
	write (2, "FAIL", 4);
}
cont = 0;
linea = "Empezamos\n*****\n";
while (linea)
{
	printf("%i:%s", cont, linea);
	linea = get_next_line(fd);
	cont++;
}
/*
   texto = get_next_line(fd);
printf("%s", texto);
printf("%s", texto);
texto = get_next_line(fd);
printf("%s", texto);
texto = get_next_line(fd);
printf("%s", texto);
texto = get_next_line(fd);
printf("%s", texto);
texto = get_next_line(fd);
printf("%s", texto);
texto = get_next_line(fd);
printf("%s", texto);
texto = get_next_line(fd);
printf("%s", texto);
*/
fd = close(fd);

return (0);
}

