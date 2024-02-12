/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:48:57 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/09 23:05:16 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_print(t_stack *stack, char *name);
void	stack_swap(t_stack *stack);
void	stack_rot(t_stack *stack);
void	stack_rrot(t_stack *stack);

void	stack_print(t_stack *stack, char *name)
{
	int	i;

	i = stack->top + 1;
	ft_printf("%s: ", name);
	while (--i >= 0)
		ft_printf("%d ", stack->data[i]);
	ft_printf("\n");
}

void	stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
	{
		ft_printf("Err: stack_swap\n");
		return ;
	}
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

void	stack_rot(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top < 1)
	{
		ft_printf("Err: stack_rot\n");
		return ;
	}
	temp = stack->data[stack->top];
	i = stack->top + 1;
	while (--i)
		stack->data[i] = stack->data[i - 1];
	stack->data[i] = temp;
}

void	stack_rrot(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top < 1)
	{
		ft_printf("Err: stack_rrot\n");
		return ;
	}
	temp = stack->data[0];
	i = -1;
	while (++i < stack->top)
		stack->data[i] = stack->data[i + 1];
	stack->data[i] = temp;
}
