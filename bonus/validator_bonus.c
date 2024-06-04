/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:45:44 by kytan             #+#    #+#             */
/*   Updated: 2024/05/20 15:45:46 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	non_int_chr(char **array, int size)
{
	char	*p;
	int		i;

	i = 0;
	while (i < size)
	{
		p = array[i++];
		if (*p == '-' || *p == '+')
			p++;
		if (!*p)
			return (1);
		while (ft_isdigit(*p))
			p++;
		if (*p)
			return (1);
	}
	return (0);
}

int	overflow(long *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] > 2147483647)
			return (1);
		if (array[i] < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	duplicates(long *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

long	*create_data_list(char **array, int size)
{
	long	*data_list;
	int		i;

	i = 0;
	data_list = malloc(size * sizeof(long));
	while (i < size)
	{
		data_list[i] = ft_atol(array[i]);
		i++;
	}
	return (data_list);
}

int	is_valid(char **array, int size)
{
	long	*data_list;
	int		i;

	if (non_int_chr(array, size))
		return (0);
	data_list = create_data_list(array, size);
	i = -1;
	if (duplicates(data_list, size) || overflow(data_list, size))
	{
		free(data_list);
		return (0);
	}
	free(data_list);
	return (1);
}
