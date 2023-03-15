/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:27:06 by htouil            #+#    #+#             */
/*   Updated: 2023/03/11 20:03:24 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *cell)
{
	char	*buffer;
	int		rd;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (ft_strchr(cell) == 0 && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1 || (rd == 0 && !cell))
		{
			free(buffer);
			if (cell)
				free(cell);
			return (NULL);
		}
		buffer[rd] = '\0';
		cell = ft_strjoin(cell, buffer);
	}
	free (buffer);
	return (cell);
}

char	*get_one_line(char *cell)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!cell[i])
		return (NULL);
	while (cell[i] != '\0' && cell[i] != '\n')
		i++;
	if (ft_strchr(cell) == 1)
		tmp = malloc((i + 2) * sizeof(char));
	else
		tmp = malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (cell[i] != '\0' && cell[i] != '\n')
	{
		tmp[i] = cell[i];
		i++;
	}
	if (cell[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*get_new_line(char *cell)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	if (!cell[i])
	{
		free (cell);
		return (NULL);
	}
	while (cell[i] != '\0' && cell[i] != '\n')
		i++;
	if (cell[i] == '\n')
		new = malloc((ft_strlen(cell) - i++) * sizeof(char));
	else
		new = malloc((ft_strlen(cell) - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	j = 0;
	while (cell[i] != '\0')
		new[j++] = cell[i++];
	new[j] = '\0';
	free(cell);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*cell[OPEN_MAX];
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	cell[fd] = ft_read(fd, cell[fd]);
	if (!cell[fd])
		return (NULL);
	one_line = get_one_line(cell[fd]);
	cell[fd] = get_new_line(cell[fd]);
	return (one_line);
}

// int	main()
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	int		i;
// 	char	*result;

// 	fd1 = open("./testfiles/multiple_lines_with_nl.txt", O_RDONLY);
// 	fd2 = open("./testfiles/1char.txt", O_RDONLY);
// 	fd3 = open("./testfiles/one_line_no_nl.txt", O_RDONLY);
// 	i = 1;
// 	while (i <= 3)
// 	{
// 		result = get_next_line(fd1);
// 		printf("\nline %d from file %d: %s", i, fd1 - 2, result);
// 		free (result);
// 		result = get_next_line(fd2);
// 		printf("\nline %d from file %d: %s", i, fd2 - 2, result);
// 		free (result);
// 		result = get_next_line(fd3);
// 		printf("\nline %d from file %d: %s", i, fd3 - 2, result);
// 		free (result);
// 		i++;
// 	}
// 	close (fd1);
// 	close (fd2);
// 	close (fd3);
// 	return (0);
// }