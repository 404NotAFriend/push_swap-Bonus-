/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:12:36 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/27 04:08:45 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/* ========================================================================== */
/*                             STRUCTURES                                     */
/* ========================================================================== */

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				keep_in_a;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* ========================================================================== */
/*                           FUNCTION PROTOTYPES                              */
/* ========================================================================== */

// Parsing & Initialization

int			parse_arguments(int argc, char**argv, t_stack *stack_a);
void		init_stack(t_stack *stack);
t_node		*create_node(int value);
void		add_bottom(t_stack *stack, t_node *new_node);

// Validation

int			is_valid_number(char *str);
int			is_overflow(char *str);
int			add_number(char *str, t_stack *stack_a);

// Stack Operations

void		sa(t_stack *stack_a, int print);
void		sb(t_stack *stack_b, int print);
void		pa(t_stack *stack_a, t_stack *stack_b, int print);
void		pb(t_stack *stack_a, t_stack *stack_b, int print);
void		ra(t_stack *stack_a, int print);
void		rb(t_stack *stack_b, int print);
void		rr(t_stack *stack_a, t_stack *stack_b, int print);
void		rra(t_stack *stack_a, int print);
void		rrb(t_stack *stack_b, int print);
void		rrr(t_stack *stack_a, t_stack *stack_b, int print);

// Sorting Algorithms

void		sort_three(t_stack *stack_a);
void		sort_small(t_stack *stack_a, t_stack *stack_b);
void		sort_large(t_stack *stack_a, t_stack *stack_b);

// Cost-based optimization

void		calculate_cost(t_stack *stack_a, t_stack *stack_b);
t_node		*find_cheapest(t_stack *stack_b);
void    execute_move(t_stack *stack_a, t_stack *stack_b, t_node *cheap);
void		push_to_b(t_stack *stack_a, t_stack *stack_b);


// Helper functions for LIS and position management

void		assign_positions(t_stack *stack);
int			find_target_pos(t_stack *stack_a, int b_index);

// LIS (Longest Increasing Subsequence) Algorithm

void		lis_sort(t_stack *stack_a, t_stack *stack_b);
void		mark_lis_elements(t_stack *stack_a);
void		push_back_optimized(t_stack *stack_a, t_stack *stack_b);

// LIS Helper Functions

void		fill_indices_array(t_stack *stack_a, int *indices,
				int *lengths, int *prev);
void		compute_lis_dp(int *indices, int *lengths,
				int *prev, int size);
void		push_non_lis_to_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_to_min(t_stack *stack_a);
int			*reconstruct_lis(int *lengths, int *prev,
				int size, int *lis_len);
void		mark_single_element(t_stack *stack_a, int target_pos);
void		find_max_lis_position(int *lengths, int size, int *max_len,
				int *max_idx);

// Optimized Small Sorts

void		sort_small(t_stack *stack_a, t_stack *stack_b);

// Indexing

void		assign_index(t_stack *stack);

// Utils

int			is_sorted(t_stack *stack);
int			has_duplicates(t_stack *stack);
void		free_stack(t_stack *stack);
void		error_exit(t_stack *stack_a, t_stack *stack_b);
int			stack_size(t_stack *stack);
t_node		*get_bottom(t_stack *stack);

#endif
