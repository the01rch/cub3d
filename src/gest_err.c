/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:57:54 by redrouic          #+#    #+#             */
/*   Updated: 2025/03/18 08:16:07 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static bool	check_valid_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W' || str[i] == 32 || str[i] == 9)
			break ;
		i++;
	}
	if ((size_t)i == ft_strlen(str))
		return (true);
	return (false);
}

static size_t	ret_map_line(char **arr)
{
	int	ret;
	int	y;

	y = 0;
	ret = -1;
	while (arr[y])
	{
		if (check_valid_line(arr[y]) && ret == -1)
			ret = y;
		if (ret != -1)
		{
			if (!check_valid_line(arr[y]))
				return (-1);
		}
		y++;
	}
	return (ret);
}

bool	is_wall(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] != '1')
			return (false);
		x++;
	}
	return (true);
}

bool	map_closed(char **arr, int y)
{
	if (!is_wall(arr[y++]))
		return (false);
	while (arr[y + 1] != NULL)
	{
		if (arr[y][0] != '1' || arr[y][ft_strlen(arr[y]) - 1] != '1')
			return (false);
		y++;
	}
	if (!is_wall(arr[y]))
		return (false);
	return (true);
}

bool	is_error(char *file)
{
	char	**arr;
	int		y;

	arr = str2arr(file, '\n');
	if (!arr)
		return (true);
	y = ret_map_line(arr);
	if (y < 0)
		return (fd_putstr("Error\nThe map is not last\n", 2), true);
	if (!map_closed(arr, y))
		return (fd_putstr("Error\nThe map is not closed\n", 2), true);
	printf("Sucess!\n");
	return (false);
}
