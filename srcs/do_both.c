/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:48 by kytan             #+#    #+#             */
/*   Updated: 2024/05/14 17:02:48 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_both(t_stack *stack_a, t_stack *stack_b,
		int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		reverse_rotate(stack_a, "", -1);
		reverse_rotate(stack_b, "", -1);
		write(1, "rrr\n", 4);
		cost_a++;
		cost_b++;
	}
	reverse_rotate(stack_a, "rra\n", cost_a);
	reverse_rotate(stack_b, "rrb\n", cost_b);
}

void	r_both(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
	while (cost_b > 0 && cost_a > 0)
	{
		rotate(stack_a, "", 1);
		rotate(stack_b, "", 1);
		write(1, "rr\n", 3);
		cost_a--;
		cost_b--;
	}
	rotate(stack_a, "ra\n", cost_a);
	rotate(stack_b, "rb\n", cost_b);
}
