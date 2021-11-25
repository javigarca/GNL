/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:16:21 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/25 17:54:16 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 00)
		i++;
	return (i);
}

int	ft_searchend(char *str, int c)
{
	size_t	i;
	char	tofind;

	i = 0;
	tofind = (char) c;
	while (str[i] != 00)
	{
		if (str[i] == tofind)
			return (i);
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
	char		*line;
	char static	*leftover;
	int			end;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	if (!leftover)
	{
		leftover = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!leftover)
			return (NULL);
	}
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	read (fd, buffer, BUFFER_SIZE);
	end = ft_searchend(buffer, 0);
	if (end != 0)
	{
		if (leftover != NULL)
		{
			line = (char *) malloc(sizeof(char) * (end + ft_strlen(leftover) + 1));
			if (!line)
				return (0);
			line = ft_strjoin(leftover, ft_feedline(buffer,end));
		}
		else
		{
			line = (char *) malloc(sizeof(char) * (end + 1));
			if (!line)
				return (0);
			line = ft_feedline(buffer, end);
		}
		free (leftover);
		free (buffer);
		return (line);
	}
	end = ft_searchend(buffer, '\n');
	if (end != 0)
	{
		if (leftover != NULL)
		{
			line = (char *) malloc(sizeof(char) * (end + ft_strlen(leftover) + 1));
			if (!line)
				return (0);
			line = ft_strjoin(leftover, ft_feedline(buffer, end));
		}
		else
		{
			line = (char *) malloc(sizeof(char) * (end + 1));
			line = ft_feedline(buffer, end);
		}
		line[end] = '\n';
		free (buffer);
		return (line);
	}
	leftover = buffer;
	free (buffer);
	get_next_line(fd);
	return (NULL);
}
