/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:57:34 by htouil            #+#    #+#             */
/*   Updated: 2023/03/13 16:56:27 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*cell;
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	cell = ft_read(fd, cell);
	if (!cell)
		return (NULL);
	one_line = get_one_line(cell);
	cell = get_new_line(cell);
	return (one_line);
}

// int main()
// {
//     int     fd;
//     char    *result; 
//     fd = open("./testfiles/multiple_lines_with_nl.txt", O_RDONLY);
//     result = get_next_line(fd);
//     printf("line 1: %s", result);
//     // result = get_next_line(fd);
//     // printf("line 2: %s", result);
//     // result = get_next_line(fd);
//     // printf("line 3: %s", result);
// 	// result = get_next_line(fd);
//     // printf("line 4: %s", result);
// 	// result = get_next_line(fd);
//     // printf("line 5: %s", result);
// 	// result = get_next_line(fd);
//     // printf("line 6: %s", result);
//     close(fd);
//     return (0);
// }

// int	main()
// {
// 	int		fd;
// 	int		i;
// 	int		j;
// 	char	*result;

// 	fd = open("./testfiles/multiple_lines_with_nl.txt", O_RDONLY);
// 	i = 1;
// 	j = 1;
// 	while (i == 1)
// 	{
// 		result = get_next_line(fd);
// 		if (result == NULL)
// 			i = 0;
// 		else
// 		{
// 			printf("line %d from file %d: %s", j, fd, result);
// 			j++;
// 		}
// 	}
// 	close (fd);
// 	return (0);
// }
