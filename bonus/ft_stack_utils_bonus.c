/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:16:30 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 09:16:30 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	free_stack(t_stack *stack)
{
	t_node	*next_node;
	t_node	*tmp;

	tmp = 0;
	next_node = stack->head;
	while (next_node)
	{
		tmp = next_node;
		next_node = next_node->next;
		free(tmp);
	}
	free(stack);
}

t_stack	*stack_alloc(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (0);
	new_stack->head = 0;
	new_stack->tail = 0;
	return (new_stack);
}

void	ft_stackadd_new(t_stack *stack, char *token)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = ft_atoi(token);
	new->stac_idx = 0;
	new->sort_idx = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	if (!(stack->head) || !(stack->tail))
		stack->head = new;
	else
		stack->tail->next = new;
	stack->tail = new;
}

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
