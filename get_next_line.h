/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thandel <thandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:18:06 by thandel           #+#    #+#             */
/*   Updated: 2023/04/29 17:13:19 by thandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_getline(char *l_str);
char	*ft_new_lstr(char *l_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *l_str, char *buff);
char	*ft_read__to_leftstr(int fd, char *l_str);

#endif
