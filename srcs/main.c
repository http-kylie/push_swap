/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:19:55 by kytan             #+#    #+#             */
/*   Updated: 2024/04/29 21:19:55 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stack *stack_a, int point)
{
	int	ra_size;
	int	rra_size;

	ra_size = rotate_moves(stack_a->head, point);
	rra_size = reverse_moves(stack_a->head, point);
	if (ra_size == 0)
		return ;
	else if (ra_size > rra_size)
		reverse_rotate(stack_a, "rra\n", -rra_size);
	else
	{
		exit(1);
		rotate(stack_a, "ra\n", ra_size);
	}
}

void	push2_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	cheapest_b;

	while (stack_b->head)
	{
		assign_stac_idx(stack_a->head, stack_b->head);
		find_cost(stack_a, stack_b);
		cheapest_b = find_cheapest(stack_b->head);
		reorder_stacks(cheapest_b, stack_a, stack_b);
		push(stack_b, stack_a, "pa\n");
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = ft_stacksize(stack_a->head);
	if (size == 2)
		swap(stack_a->head, "sa\n");
	else if (size == 3)
		sort3(stack_a->head, stack_a);
	else if (size > 3)
	{
		midpoint_sorting(stack_a, stack_b);
		sort3(stack_a->head, stack_a);
	}
	push2_stack_a(stack_a, stack_b);
	sort_stack_a(stack_a, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(0);
	stack_a = stack_alloc();
	stack_b = stack_alloc();
	if (!stack_a || !stack_b)
		return (-1);
	build_stack(argv, stack_a);
	if (!is_sorted(stack_a->head))
	{
		assign_sort_idx(stack_a->head, ft_stacksize(stack_a->head));
		push_swap(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}
