/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:57:46 by kytan             #+#    #+#             */
/*   Updated: 2024/05/14 16:57:46 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		size_b;
	t_node	*node_b;
	t_node	*head_a;
	int		target_idx;

	node_b = stack_b->head;
	head_a = stack_a->head;
	size_b = ft_stacksize(stack_b->head);
	while (node_b)
	{
		node_b->cost_b = node_b->stac_idx;
		if (node_b->stac_idx > size_b / 2)
			node_b->cost_b = (node_b->stac_idx - size_b);
		target_idx = get_target_idx(head_a, node_b);
		if (reverse_moves(head_a, target_idx)
			< rotate_moves(head_a, target_idx))
			node_b->cost_a = -reverse_moves(head_a, target_idx);
		else
			node_b->cost_a = rotate_moves(head_a, target_idx);
		node_b = node_b->next;
	}
}

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	find_cheapest(t_node *stack)
{
	int		cost_a;
	int		cost_b;
	int		cheapest;
	int		cheapest_stac_idx;

	cheapest = INT_MAX;
	while (stack)
	{
		cost_a = ft_absolute(stack->cost_a);
		cost_b = ft_absolute(stack->cost_b);
		if (cheapest > (cost_a + cost_b))
		{
			cheapest = (cost_a + cost_b);
			cheapest_stac_idx = stack->stac_idx;
		}
		stack = stack->next;
	}
	return (cheapest_stac_idx);
}
