/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:10 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/10 15:19:07 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack	t_stack;
struct	s_stack
{
	int	*data;
	int	top;
	int	capacity;
};

t_stack	*stack_new(int capacity);
void	stack_del(t_stack *stack);
void	stack_push(t_stack *stack, int value);
int		stack_pop(t_stack *stack);
int		stack_getn(t_stack *stack, int n);

void	stack_print(t_stack *stack, char *name);
void	stack_swap(t_stack *stack);
void	stack_rot(t_stack *stack);
void	stack_rrot(t_stack *stack);

#endif
