/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:16:21 by javigarc          #+#    #+#             */
/*   Updated: 2021/12/08 14:06:02 by javi_pop         ###   ########.fr       */
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
	static char	*leftover;
	int			end;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	else
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		read (fd, buffer, BUFFER_SIZE);
		end = (ft_searchend(buffer, 0) +  ft_searchend(buffer, '\n'));
		if (end == 0)
		{
			if (leftover == NULL)
				leftover = ft_feedline(buffer, ft_strlen(buffer));
			else
				leftover = ft_strjoin(leftover, buffer);
			free(buffer);
			printf("\n leftover:%s", leftover);
			get_next_line(fd);
		}
		else
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
			if ((ft_searchend(buffer, '\n') > 0))
			{
				leftover = ft_substr(buffer, end, (ft_strlen(buffer) - end));
				line[ft_strlen(line)] = '\n';
			}
			else
			{
				line[ft_strlen(line)] = 00;
			}	
//		printf("antes de return: %s", line);
			leftover = &buffer[end];
			free(buffer);
		}
		printf("\n antes line:%s", line);
		return (line);
	}
}
