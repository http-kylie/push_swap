/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:20:17 by kytan             #+#    #+#             */
/*   Updated: 2024/04/29 21:20:17 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void	bubble_sort(int *tab, int size);
void	assign_index(t_node *stack, int *sorted_list, int size);
void	assign_sort_idx(t_node *stack, int size);
void	assign_stac_idx(t_node *head_a, t_node *head_b);

void	build_stack(char **argv, t_stack *stack_a);

void	find_cost(t_stack *stack_a, t_stack *stack_b);
int		find_cheapest(t_node *stack);
int		ft_absolute(int n);

void	rr_both(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
void	r_both(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);

void	free_array(char **tokens);
void	free_error(char **tokens);
char	*ft_strtok(char *input);
long	ft_atol(const char *str);
int		arg_count(char **argv);

void	free_stack(t_stack *stack);
t_stack	*stack_alloc(void);
void	ft_stackadd_new(t_stack *stack, char *token);
int		ft_stacksize(t_node *stack);

void	sort_stack_a(t_stack *stack_a, int point);
void	push2_stack_a(t_stack *stack_a, t_stack *stack_b);
void	push_swap(t_stack *stack_a, t_stack *stack_b);

int		find_midpt(t_node *stack);
void	pb(t_stack *stack_a, t_stack *stack_b, int *i, int *total_nodes_to_go);
void	send2b(t_stack *stack_a, t_stack *stack_b, int *total_nodes_to_go);
void	midpoint_sorting(t_stack *stack_a, t_stack *stack_b);

int		rotate_moves(t_node *stack, int point);
int		reverse_moves(t_node *stack, int point);

void	push(t_stack *stack_from, t_stack *stack_to, char *instruction);
void	swap(t_node *head, char *instruction);
void	rotate(t_stack *stack, char *instruction, int cost);
void	reverse_rotate(t_stack *stack, char *instruction, int cost);

int		is_sorted(t_node *stack);
void	sort3(t_node *head, t_stack *stack_a);
void	reorder_stacks(int cheapest, t_stack *stack_a, t_stack *stack_b);

void	find_min_stac_idx(int *a_min, t_node *stack);
void	check_min_pos_diff(int *min_pos_diff, t_node *stack, t_node *node_b);
int		get_target_idx(t_node *head_a, t_node *node_b);

int		non_int_chr(char **array, int size);
int		overflow(long *array, int size);
int		duplicates(long *array, int size);
long	*create_data_list(char **array, int size);
int		is_valid(char **array, int size);

#endif