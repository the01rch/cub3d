/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:46:32 by redrouic          #+#    #+#             */
/*   Updated: 2025/03/15 08:19:39 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void	fd_putstr(const char *str, int fd);

size_t	ft_strlen(const char *str);

void	*ft_realloc(void *ptr, size_t new_size);

size_t	find_map_line(char **arr);

void	print_index(char *file, int index);

char	**str2arr(char *str, char c);

bool	is_error(char *file);
