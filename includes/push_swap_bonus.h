/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:18:23 by kytan             #+#    #+#             */
/*   Updated: 2024/05/16 12:18:23 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include ".././libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				stac_idx;
	int				sort_idx;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

int		do_valid_op(char *instruction, t_stack *stack_a, t_stack *stack_b);
void	do_op(char *instruction, t_stack *stack_a, t_stack *stack_b);
void	checker(t_stack *stack_a, t_stack *stack_b);
void	build_stack(char **argv, t_stack *stack_a);

void	rr_both(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
void	r_both(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

void	free_array(char **tokens);
void	free_error(char **tokens);
char	*ft_strtok(char *input);
int		arg_count(char **argv);
int		ft_strcmp(char *s, char *c);

void	free_stack(t_stack *stack);
t_stack	*stack_alloc(void);
void	ft_stackadd_new(t_stack *stack, char *token);
int		is_sorted(t_node *stack);

void	push(t_stack *stack_from, t_stack *stack_to);
void	swap(t_node *head);
void	rotate(t_stack *stack, int cost);
void	reverse_rotate(t_stack *stack, int cost);

int		non_int_chr(char **array, int size);
int		overflow(long *array, int size);
int		duplicates(long *array, int size);
long	*create_data_list(char **array, int size);
int		is_valid(char **array, int size);

#endif