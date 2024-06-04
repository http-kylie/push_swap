/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_idx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:57:55 by kytan             #+#    #+#             */
/*   Updated: 2024/05/15 19:57:55 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_index(t_node *stack, int *sorted_list, int size)
{
	int		i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->data == sorted_list[i])
			{
				stack->sort_idx = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	assign_sort_idx(t_node *stack, int size)
{
	t_node	*head;
	int		i;
	int		*sorted_list;

	sorted_list = malloc(sizeof(int) * size);
	if (!sorted_list)
		return ;
	i = 0;
	head = stack;
	while (stack)
	{
		sorted_list[i++] = stack->data;
		stack = stack->next;
	}
	bubble_sort(sorted_list, size);
	assign_index(head, sorted_list, size);
	free(sorted_list);
}

void	assign_stac_idx(t_node *head_a, t_node *head_b)
{
	int		i;

	i = 0;
	while (head_a)
	{
		head_a->stac_idx = i++;
		head_a = head_a->next;
	}
	i = 0;
	while (head_b)
	{
		head_b->stac_idx = i++;
		head_b = head_b->next;
	}
}
