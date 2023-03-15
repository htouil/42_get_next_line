/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:03:04 by htouil            #+#    #+#             */
/*   Updated: 2023/03/05 18:44:12 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *cell);
char	*get_one_line(char *cell);
char	*get_new_line(char *cell);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
int		ft_strchr(char *searched);

#endif
