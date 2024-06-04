/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:31:21 by kytan             #+#    #+#             */
/*   Updated: 2024/05/14 11:31:21 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midpt(t_node *stack)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (stack)
	{
		sum += stack->sort_idx;
		i++;
		stack = stack->next;
	}
	if (sum % i == 0)
		return (sum / i);
	else
		return ((sum / i) + 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b,
			int *i, int *total_nodes_to_go)
{
	push(stack_a, stack_b, "pb\n");
	(*i)--;
	(*total_nodes_to_go)--;
}

void	send2b(t_stack *stack_a, t_stack *stack_b,
			int *total_nodes_to_go)
{
	int	mid_pt;
	int	i;

	mid_pt = find_midpt(stack_a->head);
	i = (((*total_nodes_to_go) / 2) + 1);
	while (i > 0)
	{
		if ((stack_a->head)->sort_idx < mid_pt)
			pb(stack_a, stack_b, &i, total_nodes_to_go);
		else if ((stack_a->head)->next->sort_idx < mid_pt)
		{
			rotate(stack_a, "ra\n", 1);
			pb(stack_a, stack_b, &i, total_nodes_to_go);
		}
		else if ((stack_a->tail)->sort_idx < mid_pt)
		{
			reverse_rotate(stack_a, "rra\n", -1);
			pb(stack_a, stack_b, &i, total_nodes_to_go);
		}
		else
			rotate(stack_a, "ra\n", 1);
	}
}

void	midpoint_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	total_nodes_to_go;

	total_nodes_to_go = ft_stacksize(stack_a->head) - 3;
	while (total_nodes_to_go > 0)
		send2b(stack_a, stack_b, &total_nodes_to_go);
}

/*
void	send2b(t_stack *a, t_stack *b, int *total_nodes_to_go)
{
	int	mid_pt;
	int	i;

	mid_pt = find_midpt(*a);
	i = (((*total_nodes_to_go) / 2) + 1);
	while (i > 0)
	{
		if ((*a)->sort_idx < mid_pt)
			pb(stack_a, stack_b, &i, total_nodes_to_go);
		else if ((*a)->next->sort_idx < mid_pt)
		{
			rotate(a, "ra", 1);
			pb(stack_a, stack_b, &i, total_nodes_to_go);
		}
		else if ((lstlast(*a)->sort_idx < mid_pt))
		{
			reverse_rotate(a, "rra", -1);
			pb(stack_a, stack_b, &i, total_nodes_to_go);
		}
		else
			rotate(a, "ra", 1);
	}
}

void	midpoint_sorting(t_stack *a, t_stack *b)
{
	int	total_nodes_to_go;

	total_nodes_to_go = find_len(*a) - 3;
	while (total_nodes_to_go > 0)
		send2b(a, b, &total_nodes_to_go);
}

printf("top i: %i\n", i);
		printf("head_a->sort_idx: %i\n", head_a->sort_idx);
		ft_print_stac_idx(stack_a);
		printf("head_a->next->sort_idx: %i\n", head_a->next->sort_idx);
		printf("tail_a->sort_idx: %i\n", tail_a->sort_idx);


	printf("tntg: %i\n%p\n", *total_nodes_to_go, total_nodes_to_go);
	printf("stack_a: %p\n", stack_a);
	printf("stack_a: %p\n", stack_a->head);
	printf("stack_a: %p\n", stack_a->tail);
	printf("stack_b: %p\n", stack_b);
	printf("stack_a: %p\n", stack_a->head);
	printf("stack_a: %p\n", stack_a->tail);

		//printf("i: %i\n", i);
		//total_nodes_to_go = 0;
		//return ;
	}
*/