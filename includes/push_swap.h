/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:12:36 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/21 17:31:14 by bramalho@st      ###   ########.fr       */
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

// Stack Operations

void		sa(t_stack *stack_a, int print);
void		sb(t_stack *stack_b, int print);
void		ss(t_stack *stack_a, t_stack *stack_b, int print);
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

// Utils
int			is_sorted(t_stack *stack);
int			has_duplicates(t_stack *stack);
void		free_stack(t_stack *stack);
void		error_exit(t_stack *stack_a, t_stack *stack_b);
int			stack_size(t_stack *stack);
t_node		*get_bottom(t_stack *stack);

#endif
