/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:48:10 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/24 19:10:49 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	buffer[1];
	char	*line;
	
	i = 0;
	line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	read (fd, buffer, 1);  	   
	while ((*buffer != '\n') || (i <= BUFFER_SIZE) || (*buffer == 0))
		{
			line[i] = *buffer;
			read (fd, buffer, 1);
			i++;
		}
	if (*buffer == 0)
	   return (0);   	   
	line[i] = '\n';
	return (line);
}
