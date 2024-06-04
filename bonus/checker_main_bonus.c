/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:15:46 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 09:15:46 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	do_valid_op(char *instruction,
		t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		swap(stack_a->head);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		swap(stack_a->head);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		rotate(stack_a, 1);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rotate(stack_b, 1);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		r_both(stack_a, stack_b, 1, 1);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		reverse_rotate(stack_a, -1);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		reverse_rotate(stack_b, -1);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rr_both(stack_a, stack_b, -1, -1);
	else
		return (0);
	return (1);
}

void	do_op(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	int		valid;

	valid = do_valid_op(instruction, stack_a, stack_b);
	if (!valid)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		free(instruction);
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
}

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*instruction;

	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		do_op(instruction, stack_a, stack_b);
		free(instruction);
	}
	if (is_sorted(stack_a->head) && stack_b->head == NULL)
		write(STDOUT_FILENO, "OK\n", 3);
	else if (!is_sorted(stack_a->head) || (stack_b->head) != NULL)
		write(STDOUT_FILENO, "KO\n", 3);
}

void	build_stack(char **argv, t_stack *stack_a)
{
	int			i;
	static char	**tokens;

	tokens = malloc((arg_count(argv) + 1) * sizeof(char *));
	if (!tokens)
		return ;
	i = 0;
	while (*(++argv))
	{
		if (!**argv)
			free_error(tokens);
		tokens[i] = ft_strtok(*argv);
		while (tokens[i])
			tokens[++i] = ft_strtok(0);
	}
	if (!is_valid(tokens, i))
		free_error(tokens);
	i = 0;
	while (tokens[i])
		ft_stackadd_new(stack_a, tokens[i++]);
	free_array(tokens);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = stack_alloc();
	stack_b = stack_alloc();
	if (!stack_a || !stack_b)
		return (1);
	build_stack(argv, stack_a);
	checker(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
