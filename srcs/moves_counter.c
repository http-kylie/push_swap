/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:12 by kytan             #+#    #+#             */
/*   Updated: 2024/05/15 19:59:12 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_moves(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->sort_idx != point)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	reverse_moves(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->sort_idx != point)
		stack = stack->next;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
