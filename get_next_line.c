/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:16:21 by javigarc          #+#    #+#             */
/*   Updated: 2022/01/12 14:36:32 by javigarc         ###   ########.fr       */
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
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	static char	*leftover;
	int			end;
	int			eof;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1 ));
	if (!buffer)
		return (0);
	read (fd, buffer, BUFFER_SIZE);
	eof = ft_searchend(buffer, '\0');
	end = ft_searchend(buffer, '\n');
	if (end == 0)
	{
		if (eof == 0)
		{
			if (leftover == NULL)
				leftover = ft_feedline(buffer, ft_strlen(buffer));
			else
				leftover = ft_stradd(leftover, buffer);
			free(buffer);
			get_next_line(fd);
		}
		else
			return(ft_create_line(buffer, leftover, eof));
	} 
	else
	{
		next_line = ft_strdup(ft_create_line(buffer, leftover, end));
		if (eof > 0)
			leftover = NULL;
		else
			leftover = ft_substr(buffer, end, (ft_strlen(buffer) - end));
		free(buffer);
		return (next_line);
	}
	return(NULL);
}

char	*ft_create_line(char *buf, char *leftovr, int len)
{
	char *line;

	if (leftovr != NULL)
	{
		line = (char *) malloc(sizeof(char) * (len + ft_strlen(leftovr) + 1));
		if (!line)
			return (0);
		line = ft_stradd(leftovr, ft_feedline(buf, len));	
	}
	else
	{
		line = (char *) malloc(sizeof(char) * (len + 1));
		if (!line)
			return (0);
		line = ft_feedline(buf, len);
	}
	return (line);
}

