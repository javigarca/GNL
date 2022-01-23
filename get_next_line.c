/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:16:21 by javigarc          #+#    #+#             */
/*   Updated: 2022/01/13 13:31:08 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_searchend(char *str, int c)
{
	size_t	i;
	char	tofind;

	i = 0;
	tofind = (char) c;
	while (str[i] != 00)
	{
		if (str[i] == tofind)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_feedline(char *str, int len)
{
	char	*aux;
	int		i;

	i = 0;
	aux = (char *) malloc(sizeof(char) * (len + 1));
	if (!aux)
		return (0);
	while (i < len)
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

int	ft_readfile(int fdr, char **ldr)
{
	char	*buffer;
	int		bytes;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes = read (fdr, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	if (bytes == 0)
	{
		if (!*ldr)
			return (-1);
	}
	else
	{
		if (!*ldr)
			*ldr = buffer;
		else
			*ldr = ft_stradd(*ldr, buffer);
	}
	buffer = NULL;
	free(buffer);
	return (bytes);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*loader;
	int			eof;
	int			end;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	if (!loader)
		loader = NULL;
	line = NULL;
	eof = BUFFER_SIZE;
	end = 0;
	while ((end == 0) && (eof == BUFFER_SIZE))
	{
		eof = ft_readfile(fd, &loader);
		if (eof < 0)
			return (NULL);
		end = ft_searchend(loader, '\n');
		if ((end == 0) && (eof < BUFFER_SIZE))
			end = eof;
	}
	line = ft_strdup(get_next_line_2(&loader, end));
	return (line);
}

char	*get_next_line_2(char **ldr, int endb)
{	
	char	*aux;

	if (endb == 0)
	{
		aux = (char *) malloc (sizeof(char) * (ft_strlen(*ldr) + 1));
		if (!aux)
			return (0);
		aux = *ldr;
	}
	else
	{
		aux = (char *) malloc (sizeof(char) * (endb + 1));
		if (!aux)
			return (0);
		aux = ft_feedline(*ldr, endb);
		*ldr = ft_substr(*ldr, endb, (ft_strlen(*ldr) - endb));
	}
	return (aux);
}
