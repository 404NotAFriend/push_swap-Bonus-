/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 09:15:30 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/25 22:30:45 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

// Parsing & Initialization (reuse from mandatory)
int			parse_arguments(int argc, char **argv, t_stack *stack_a);
void		init_stack(t_stack *stack);
t_node		*create_node(int value);
void		add_bottom(t_stack *stack, t_node *new_node);

// Validation (reuse from mandatory)
int			is_valid_number(char *str);
int			is_overflow(char *str);
int			add_number(char *str, t_stack *stack_a);

// Stack Operations (WITHOUT PRINT - bonus versions)
void		sa_bonus(t_stack *stack_a);
void		sb_bonus(t_stack *stack_b);
void		ss_bonus(t_stack *stack_a, t_stack *stack_b);
void		pa_bonus(t_stack *stack_a, t_stack *stack_b);
void		pb_bonus(t_stack *stack_a, t_stack *stack_b);
void		ra_bonus(t_stack *stack_a);
void		rb_bonus(t_stack *stack_b);
void		rr_bonus(t_stack *stack_a, t_stack *stack_b);
void		rra_bonus(t_stack *stack_a);
void		rrb_bonus(t_stack *stack_b);
void		rrr_bonus(t_stack *stack_a, t_stack *stack_b);

// Get Next Line
char		*get_next_line(int fd);

// Operation Reading & Execution
int			read_and_execute(t_stack *stack_a, t_stack *stack_b);
int			execute_operation(char *line, t_stack *stack_a, t_stack *stack_b);
int			execute_swap_ops(char *line, t_stack *stack_a, t_stack *stack_b);
int			execute_push_ops(char *line, t_stack *stack_a, t_stack *stack_b);
int			execute_rotate_ops(char *line, t_stack *stack_a, t_stack *stack_b);
int			ft_strcmp(const char *s1, const char *s2);

// Utils (reuse from mandatory)
int			is_sorted(t_stack *stack);
int			has_duplicates(t_stack *stack);
void		free_stack(t_stack *stack);
void		error_exit(t_stack *stack_a, t_stack *stack_b);
int			stack_size(t_stack *stack);
t_node		*get_bottom(t_stack *stack);

#endif
