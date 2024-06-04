/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:51 by kytan             #+#    #+#             */
/*   Updated: 2024/05/15 19:59:51 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_to, char *instruction)
{
	t_node	*push_node;

	if (!stack_from || !(stack_from->head) || !stack_to)
		return ;
	push_node = stack_from->head;
	stack_from->head = stack_from->head->next;
	if (stack_from->head == NULL)
		stack_from->tail = NULL;
	push_node->next = stack_to->head;
	stack_to->head = push_node;
	if (stack_to->head->next == NULL)
		stack_to->tail = push_node;
	write(1, instruction, ft_strlen(instruction));
}

void	swap(t_node *head, char *instruction)
{
	int	tmp_data;
	int	tmp_sort_idx;

	if (!head || !(head->next))
		return ;
	tmp_data = head->data;
	tmp_sort_idx = head->sort_idx;
	head->data = head->next->data;
	head->sort_idx = head->next->sort_idx;
	head->next->data = tmp_data;
	head->next->sort_idx = tmp_sort_idx;
	write(1, instruction, ft_strlen(instruction));
}

void	rotate(t_stack *stack, char *instruction, int cost)
{
	if (!stack || !(stack->head) || !(stack->tail))
		return ;
	while (cost)
	{
		stack->tail->next = stack->head;
		stack->head = stack->head->next;
		stack->tail = stack->tail->next;
		stack->tail->next = NULL;
		write(1, instruction, ft_strlen(instruction));
		cost--;
	}
}

void	reverse_rotate(t_stack *stack, char *instruction, int cost)
{
	t_node	*last_node;

	if (!stack || !(stack->head) || !(stack->tail))
		return ;
	while (cost < 0)
	{
		stack->tail->next = stack->head;
		while (stack->head->next != stack->tail)
			stack->head = stack->head->next;
		last_node = stack->head;
		stack->head = stack->tail;
		stack->tail = last_node;
		stack->tail->next = NULL;
		write(1, instruction, ft_strlen(instruction));
		cost++;
	}
}
/*
void	ft_print_stac_idx(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->head;
	while (tmp)
	{
		printf("%i(%i)->", tmp->data, tmp->stac_idx);
		if (!(tmp->next))
			printf("NULL\n");
		tmp = tmp->next;
	}
}*/
