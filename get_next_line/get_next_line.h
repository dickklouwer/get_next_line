/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:23:38 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/12/11 15:39:54 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFFER_SIZE    32
# define GNL_ERROR      -1
# define EOF            0
# define READING        1

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_memccpy(char *dst, char *src, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*buf_move(char *buf);
int		next_line(char *buf, char **line);

# endif


