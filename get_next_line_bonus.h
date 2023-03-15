/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:27:18 by htouil            #+#    #+#             */
/*   Updated: 2023/03/11 19:27:20 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

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