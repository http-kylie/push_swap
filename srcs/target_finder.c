/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:56:08 by kytan             #+#    #+#             */
/*   Updated: 2024/05/15 19:56:08 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_stac_idx(int *a_min, t_node *stack)
{
	*a_min = stack->sort_idx;
	while (stack->next != NULL)
	{
		if (*a_min > stack->next->sort_idx)
			*a_min = stack->next->sort_idx;
		stack = stack->next;
	}
}

void	check_min_pos_diff(int *min_pos_diff, t_node *stack, t_node *node_b)
{
	int		next_diff;

	*min_pos_diff = INT_MAX;
	if ((stack->sort_idx - node_b->sort_idx) > 0)
		*min_pos_diff = (stack->sort_idx - node_b->sort_idx);
	while (stack->next)
	{
		next_diff = stack->next->sort_idx - node_b->sort_idx;
		if (*min_pos_diff > next_diff && next_diff > 0)
			*min_pos_diff = next_diff;
		stack = stack->next;
	}
}

int	get_target_idx(t_node *head_a, t_node *node_b)
{
	int		min_pos_diff;
	int		target;
	int		a_min;

	target = 0;
	check_min_pos_diff(&min_pos_diff, head_a, node_b);
	find_min_stac_idx(&a_min, head_a);
	if (min_pos_diff > 0)
		target = min_pos_diff + node_b->sort_idx;
	else if (min_pos_diff < 0)
		target = a_min;
	return (target);
}
