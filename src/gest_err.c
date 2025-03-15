/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:57:54 by redrouic          #+#    #+#             */
/*   Updated: 2025/03/15 08:47:15 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static inline bool	valid_format(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\t');
}

bool	check_valid_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!valid_format(str[i]))
			break ;
		i++;
	}
	if ((size_t)i == ft_strlen(str))
		return (true);
	return (false);
}

size_t	ret_map_line(char **arr)
{
	int	ret;
	int	y;

	y = 0;
	ret = -1;
	while (arr[y])
	{
		if (check_valid_line(arr[y]))
		{
			ret = y;
			break ;
		}
		y++;
	}
	if (ret != -1)
	{
		y = ret;
		while (arr[y])
		{
			if (!check_valid_line(arr[y]))
				return (fd_putstr("Error\nThe map is no last\n", 2), -1);
			y++;
		}
	}
	return (ret);
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
		return (false);
	printf("arr[y] : %s\n", arr[y]);
	return (false);
}
