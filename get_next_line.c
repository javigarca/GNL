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
	return (aux);
}

void	ft_free_var(char *var)
{
	free(var);
	var = NULL;
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*nxt_ln;
	static char	*loader;
	int			eof;
	int			end;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	eof = read (fd, buffer, BUFFER_SIZE);
	if (eof == 0)
	{
		free(buffer);
		buffer = NULL;
		return(NULL);
	}
	else
	{
		if (!loader)
			loader = ft_strdup(buffer);
		else
		{
	//		printf("llenando el loader con buffer");
			loader = ft_stradd(loader,buffer);
		}
	}
	end = ft_searchend(loader, '\n');
	free(buffer);
	buffer = NULL;
	nxt_ln = NULL;
	if (end == 0)
	{
		if (ft_searchend(loader, '\0') == 0)
		{
		//	printf("LOD: %s\n", loader);
			get_next_line(fd);
		}
		else
		{
		//	printf("LOD2: %s\n", loader);
			nxt_ln = ft_strdup(loader);
		}
	}
	else
	{
		nxt_ln = ft_feedline(loader,end);
		loader = ft_substr(loader, end, (ft_strlen(loader) - end));
//		printf("loader: %s*\n", loader);
//		printf("next line: %s*\n", nxt_ln);
	}
	return (nxt_ln);
}
