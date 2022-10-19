/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:33 by mjulliat          #+#    #+#             */
/*   Updated: 2022/10/19 17:30:15 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			count;

	count = 0;
	line = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!line)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	line = buffer;
	return (line);
}

int	main(void)
{
	int	fd;
	char *test;

	fd = open("test.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	close(fd);
	free(test);
	test = 0;
	return (0);
}
