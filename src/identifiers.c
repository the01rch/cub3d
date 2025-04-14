/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:11:46 by redrouic          #+#    #+#             */
/*   Updated: 2025/04/14 22:17:07 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	count_arr(char **arr)
{
	(void)arr;
	return (0);
}

bool	is_id(char *str)
{
	if (!ft_strcmp(str, "NO") && !ft_strcmp(str, "SO")
		&& !ft_strcmp(str, "WE") && !ft_strcmp(str, "EA")
		&& !ft_strcmp(str, "F") && !ft_strcmp(str, "C"))
		return (fd_putstr("Error\nInvalid Identifier\n", 2), false);
	return (true);
}

bool	valid_id(char **arr, int line)
{
	char	**tab;
	int		y;

	y = 0;
	while (y < line)
	{
		printf("arr = %s\n", arr[y]);
		tab = str2arr(arr[y], ' ');
		printf("tab[0] = %s\n", tab[0]);
		if (!is_id(tab[0]))
			return (false);
		if (!tab[1])
			return (fd_putstr("Error\nNo ID content provided\n", 2), false);
		(free(tab[0]), free(tab[1]));
		tab = 0;
		y++;
	}
	return (true);
}
