/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thandel <thandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:16:00 by thandel           #+#    #+#             */
/*   Updated: 2023/04/30 14:28:15 by thandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <stdio.h>

int		main()
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
}
*/
char	*ft_read_to_leftstr(int fd, char *l_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(l_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		l_str = ft_strjoin((char *)l_str, buff);
	}
	free(buff);
	return (l_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*l_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (l_str)
			free(l_str);
		l_str = NULL;
		return (NULL);
	}
	l_str = ft_read_to_leftstr(fd, l_str);
	if (!l_str)
		return (NULL);
	line = ft_getline(l_str);
	l_str = ft_new_lstr(l_str);
	return (line);
}
