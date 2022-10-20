/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:33 by mjulliat          #+#    #+#             */
/*   Updated: 2022/10/20 15:50:21 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_join(char *buffer, char *str)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	free(buffer);
	return (tmp);
}

char	*read_buffer(int fd, char *str)
{
	char	*buffer;
	int		byte_read;

	if (!str)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
	}
	byte_read = 1;
	while (byte_read > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		str = free_and_join(buffer, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	(void) line;
	buffer = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	// trim le buffer pour avoir la ligne jusqu'au "\n"
	// trim le buffer pour recommencer la fonction depuis le +1 du "\n"
	return (buffer);
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
