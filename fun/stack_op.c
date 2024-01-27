/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:48:57 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/27 18:37:19 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack);
void	rot(t_stack *stack);
void	rrot(t_stack *stack);

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
		return ;
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

void	rot(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top < 1)
		return ;
	temp = stack->data[stack->top];
	i = stack->top + 1;
	while (--i)
		stack->data[i] = stack->data[i - 1];
	stack->data[i] = temp;
}

void	rrot(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top < 1)
		return ;
	temp = stack->data[0];
	i = -1;
	while (++i < stack->top)
		stack->data[i] = stack->data[i + 1];
	stack->data[i] = temp;
}
