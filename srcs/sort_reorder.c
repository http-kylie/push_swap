/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:30:06 by kytan             #+#    #+#             */
/*   Updated: 2024/05/15 20:30:06 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort3(t_node *head, t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = head->sort_idx;
	second = head->next->sort_idx;
	third = head->next->next->sort_idx;
	if (first > second && first > third)
		rotate(stack_a, "ra\n", 1);
	else if (second > first && second > third)
		reverse_rotate(stack_a, "rra\n", -1);
	if (!is_sorted(stack_a->head))
		swap(stack_a->head, "sa\n");
}

void	reorder_stacks(int cheapest, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_b;

	node_b = stack_b->head;
	while (node_b->stac_idx != cheapest)
		node_b = node_b->next;
	if ((node_b->cost_a < 0) && (node_b->cost_b < 0))
		rr_both(stack_a, stack_b, node_b->cost_a, node_b->cost_b);
	else if ((node_b->cost_a > 0) && (node_b->cost_b > 0))
		r_both(stack_a, stack_b, node_b->cost_a, node_b->cost_b);
	else if (node_b->cost_b >= 0 && node_b->cost_a <= 0)
	{
		rotate(stack_b, "rb\n", node_b->cost_b);
		reverse_rotate(stack_a, "rra\n", node_b->cost_a);
	}
	else if (node_b->cost_b <= 0 && node_b->cost_a >= 0)
	{
		reverse_rotate(stack_b, "rrb\n", node_b->cost_b);
		rotate(stack_a, "ra\n", node_b->cost_a);
	}
}
