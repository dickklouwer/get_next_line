/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:28:11 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/12/11 15:47:00 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		out_check(int ret, int nbytes, char *buf, char **line)
{
	if (ret < 0 && nbytes < 0)
	{
		free(*line);
		return (GNL_ERROR);
	}
	if (ret == 0 && ft_strlen(buf))
		return (READING);
	else if (nbytes < BUFFER_SIZE && !ft_strlen(buf))
		return (EOF);
	else
		return (READING);
}

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
		return (GNL_ERROR);
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
		return (GNL_ERROR);
	*line = ft_strdup("");
	ret = next_line(buf, line);
	if (ret)
		return (out_check(ret, nbytes, buf, line));
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		buf[nbytes] = '\0';
		if (nbytes < 0)
			return (out_check(ret, nbytes, buf, line));
		ret = next_line(buf, line);
		if (ret)
		{
			*buf = *buf_move(buf);
			return (out_check(ret, nbytes, buf, line));
		}
	}
	return (EOF);
}
