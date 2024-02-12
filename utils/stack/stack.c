/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:43:00 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/09 23:04:39 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int capacity);
void	stack_del(t_stack *stack);
void	stack_push(t_stack *stack, int value);
int		stack_pop(t_stack *stack);
int		stack_getn(t_stack *stack, int n);

t_stack	*stack_new(int capacity)
{
	t_stack	*ret;

	ret = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->capacity = capacity;
	ret->top = -1;
	ret->data = (int *)ft_calloc(capacity, sizeof(int));
	if (!ret->data)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

void	stack_del(t_stack *stack)
{
	free(stack->data);
	free(stack);
}

void	stack_push(t_stack *stack, int value)
{
	if (stack->top == stack->capacity - 1)
	{
		ft_printf("Error: Stack overflow!\n");
		return ;
	}
	stack->data[++stack->top] = value;
}

int	stack_pop(t_stack *stack)
{
	if (stack->top == -1)
	{
		ft_printf("Error: Stack underflow!\n");
		return (0);
	}
	return (stack->data[stack->top--]);
}

int	stack_getn(t_stack *stack, int n)
{
	if (n < 0 || n > stack->top)
	{
		ft_printf("Error: Invalid position!\n");
		return (0);
	}
	return (stack->data[stack->top - n]);
}
