/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:35:56 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/12/11 13:19:35 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	char	**line;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (get_next_line(fd, line) == 1)
	{
		printf("line: %s\n", *line);
		free(*line);
	}
	close(fd);
}
