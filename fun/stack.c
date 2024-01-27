/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:43:00 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/27 20:30:14 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int capacity);
void	stack_del(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	stack_print(t_stack *stack, char *name);

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

void	push(t_stack *stack, int value)
{
	if (stack->top == stack->capacity - 1)
	{
		ft_printf("Error: Stack overflow!\n");
		return ;
	}
	stack->data[++stack->top] = value;
}

int	pop(t_stack *stack)
{
	if (stack->top == -1)
	{
		ft_printf("Error: Stack underflow!\n");
		return (0);
	}
	return (stack->data[stack->top--]);
}

void	stack_print(t_stack *stack, char *name)
{
	int	i;

	i = stack->top + 1;
	ft_printf("%s: ", name);
	while (--i >= 0)
		ft_printf("%d ", stack->data[i]);
	ft_printf("\n");
}
