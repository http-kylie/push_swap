/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_both_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:15:57 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 09:15:57 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	rr_both(t_stack *stack_a, t_stack *stack_b,
			int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		reverse_rotate(stack_a, -1);
		reverse_rotate(stack_b, -1);
		cost_a++;
		cost_b++;
	}
	reverse_rotate(stack_a, cost_a);
	reverse_rotate(stack_b, cost_b);
}

void	r_both(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
	while (cost_b > 0 && cost_a > 0)
	{
		rotate(stack_a, 1);
		rotate(stack_b, 1);
		cost_a--;
		cost_b--;
	}
	rotate(stack_a, cost_a);
	rotate(stack_b, cost_b);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a->head);
	swap(stack_b->head);
}
