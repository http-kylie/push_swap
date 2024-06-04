/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:16:15 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 09:16:15 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

int	ft_strcmp(char *s, char *c)
{
	while (*s == *c && *s)
	{
		++s;
		++c;
	}
	return (*s - *c);
}
