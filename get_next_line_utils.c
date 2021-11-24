/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:47:34 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/24 18:07:33 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	ft_read_first_line( char *fd, t_board *board)
{
	int				i;
	int				filedescriptor;
	char			buffer[1];
	char			*buf;

	buf = malloc(15 * sizeof(char));
	filedescriptor = 0;
	filedescriptor = open(fd, O_RDONLY);
	if (filedescriptor == -1)
		return (ft_return_error());
	i = 0;
	ft_readline(filedescriptor, buf);
	if (ft_map_check_line1(buf, board) != TRUE)
		return (ft_return_error());
	read(filedescriptor, buffer, 1);
	while (buffer[0] != '\n')
	{
		read(filedescriptor, buffer, 1);
		i++;
	}
	ft_map_insert_cols(board, i);
	free(buf);
	close(filedescriptor);
	return (TRUE);
}

int	ft_read_file(char *fd)
{
	int				filedescriptor;
	t_board			board;
	char			*buf;
	char			*buf2;

	buf = malloc(15 * sizeof(char));
	(void)board;
	if (ft_read_first_line(fd, &board) == TRUE)
	{
		buf2 = malloc(N_CHARS * sizeof(char));
		filedescriptor = open(fd, O_RDONLY);
		ft_readline(filedescriptor, buf);
		ft_readnlines(filedescriptor, board.rows, buf2);
		if (ft_map_check_valid(buf2, &board) != TRUE)
			return (ft_return_error());
		ft_board_populate(buf2, &board);
		close(filedescriptor);
		ft_solution(&board);
		ft_board_insert_sol(board);
		ft_board_print(board);
		return (FALSE);
	}
	return (TRUE);
}
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 00)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_sz;
	size_t	s_sz;

	d_sz = 0;
	s_sz = 0;
	while (dest[d_sz] != 00)
		d_sz++;
	while (src[s_sz] != 00)
		s_sz++;
	i = d_sz;
	j = 0;
	if (size < 1)
		return (s_sz + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < d_sz)
		return (s_sz + size);
	return (d_sz + s_sz);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pos;
	char	*string;
	int		totalsize;

	if ((!s1) || (!s2))
		return (NULL);
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	pos = (size_t)totalsize + 1;
	string = (char *)malloc(sizeof(char) * (totalsize) + 1);
	if (!string)
		return (0);
	ft_strlcpy(string, s1, ft_strlen(s1) + 1);
	ft_strlcat(string, s2, pos);
	string[ft_strlen(string)] = 00;
	return (string);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	rtrn;

	i = 0;
	rtrn = 0;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != 00))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 00;
	}
	while (src[rtrn] != 00)
		rtrn++;
	return (rtrn);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dst;

	len = 0;
	while (src[len] != '\0')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		exit (1);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
void	ft_readline(int filedescriptor, char str[15])
{
	int		i;
	char	buffer[1];

	i = 0;
	read(filedescriptor, buffer, 1);
	while (buffer[0] != '\n')
	{
		str[i] = buffer[0];
		read(filedescriptor, buffer, 1);
		i++;
	}
}

void	ft_readnlines(int filedescriptor, int lines, char str[N_CHARS])
{
	int		i;
	char	buffer[1];

	i = 0;
	read(filedescriptor, buffer, 1);
	while (lines > 0)
	{
		str[i] = buffer[0];
		read(filedescriptor, buffer, 1);
		if (buffer[0] == '\n')
			lines--;
		i++;
	}
}*/
