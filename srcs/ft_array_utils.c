/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:21 by kytan             #+#    #+#             */
/*   Updated: 2024/05/15 19:58:21 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

void	free_error(char **tokens)
{
	free_array(tokens);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

char	*ft_strtok(char *input)
{
	int			i;
	static char	*last;
	char		*token;

	i = 0;
	if (input != NULL)
		last = input;
	while (*last == ' ')
		last++;
	if (*last == '\0')
		return (0);
	while (last[i] != ' ' && last[i])
		i++;
	token = malloc(i + 1);
	i = 0;
	while (*last != ' ' && *last)
		token[i++] = *last++;
	token[i] = '\0';
	return (token);
}

long	ft_atol(const char *str)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int	arg_count(char **argv)
{
	int		ct;
	char	*s;

	ct = 0;
	while (*(++argv))
	{
		s = *argv;
		while (*s)
		{
			if (*s != ' ' && (*(s + 1) == ' ' || *(s + 1) == 0))
				ct++;
			s++;
		}
	}
	return (ct);
}
