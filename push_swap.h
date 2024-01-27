/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:37:19 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/27 13:47:38 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/* Stack */
typedef struct s_stack	t_stack;
struct	s_stack
{
	int	*data;
	int	top;
	int	capacity;
};

/* Stack Functions */
t_stack	*stack_new(int capacity);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	stack_print(t_stack *stack, char *name);

/* Stack OP Functions */
void	swap(t_stack *stack);
void	rot(t_stack *stack);
void	rrot(t_stack *stack);

/* Push Swap */
typedef struct s_ps		t_ps;
struct	s_ps
{
	t_stack	*a;
	t_stack	*b;
};

/* push_swap operations */
void	ps_sa(t_ps *ps); /* swap a */
void	ps_sb(t_ps *ps); /* swap b */
void	ps_ss(t_ps *ps); /* swap all */

void	ps_pa(t_ps *ps); /* push a */
void	ps_pb(t_ps *ps); /* push b */

void	ps_ra(t_ps *ps); /* rotate a */
void	ps_rb(t_ps *ps); /* rotate b */
void	ps_rr(t_ps *ps); /* rotate all */

void	ps_rra(t_ps *ps); /* reverse rotate a */
void	ps_rrb(t_ps *ps); /* reverse rotate b */
void	ps_rrr(t_ps *ps); /* reverse rotate all */

/* Other */
int		ft_strtoi(char *str);

#endif
