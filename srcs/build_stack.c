/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:05 by kytan             #+#    #+#             */
/*   Updated: 2024/05/15 19:58:05 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_stack(char **argv, t_stack *stack_a)
{
	int			i;
	static char	**tokens;

	tokens = malloc((arg_count(argv) + 1) * sizeof(char *));
	if (!tokens)
		return ;
	i = 0;
	while (*(++argv))
	{
		if (!**argv)
			free_error(tokens);
		tokens[i] = ft_strtok(*argv);
		while (tokens[i])
			tokens[++i] = ft_strtok(0);
	}
	if (!is_valid(tokens, i))
		free_error(tokens);
	i = 0;
	while (tokens[i])
		ft_stackadd_new(stack_a, tokens[i++]);
	free_array(tokens);
}
