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

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*loader;
	int			eof;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	eof = read (fd, buffer, BUFFER_SIZE);
	if (eof == 0)
	{
		if (!loader)
			return (NULL);
	}
	else
		if (!loader)
			loader = buffer;
		else
			loader = ft_stradd(loader, buffer);
	buffer = NULL;
//	line = NULL;
	free(buffer);
	line = ft_strdup(get_next_line_2(&loader, eof, BUFFER_SIZE, fd));
	return (line);
}

char	*get_next_line_2(char **ldr, int eofb, int bufflen, int fdb)
{	
	int		end;
	char	*aux;

	end = ft_searchend(*ldr, '\n');
	if (end == 0)
	{
		if (eofb == bufflen)
			get_next_line(fdb);
		aux = ft_strdup(*ldr);
	}
	else
	{
		aux = ft_feedline(*ldr, end);
		*ldr = ft_substr(*ldr, end, (ft_strlen(*ldr) - end));
	}
	return (aux);
}
