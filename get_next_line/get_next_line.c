/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:28:11 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/12/10 20:54:40 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int		count_line(char *str, int n)
// {
// 	int		i;

// 	i = 0;
// 	if (n == 0)
// 		return (-1);
// 	while (i < n)
// 	{
// 		if (str[i] == '\n')
// 			return (1);
// 		if (str[i] == '\0')
// 			return (0);
// 		i++;
// 	}
// 	return (-1);
// }

char	*buf_move(char *buf)
{
	int		i;
	char	*address;

	i = 0;
	address = ft_strchr(buf, '\n');
	ft_memccpy(buf, address + 1, '\n', BUFFER_SIZE);
	i = ft_strlen(buf);
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
	return (buf);
}

int		next_line(char *buf, char **line)
{
	char	*temp;
	int		len;

	len = (ft_strlen(buf) + ft_strlen(*line));
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (!temp)
		return (-1);
	ft_memccpy(temp, *line, '\n', ft_strlen(*line));
	ft_memccpy(temp + ft_strlen(*line), buf, '\n', ft_strlen(buf));
	temp[len] = '\0';
	free(*line);
	*line = temp;
	len = ft_strchr(buf, '\n') == NULL ? 0 : 1;
	return (len);
}

int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				nbytes;
	int				ret;

	if (!fd || !line || BUFFER_SIZE < 0)
		return (-1);
	*line = ft_strdup("");
	if (*buf)
		ft_memccpy(*line, buf, '\n', BUFFER_SIZE);
	ret = ft_strchr(*line, '\n') == NULL ? 0 : 1;
	while (ret == 0 && nbytes > 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes < 0)
			return (-1);
		buf[BUFFER_SIZE] = '\0';
		ret = next_line(buf, line);
	}
	*buf = *buf_move(buf);
	if (nbytes == 0)
		return (0);
	return (ret);
}
