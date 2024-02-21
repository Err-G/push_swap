/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:14:16 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 12:33:16 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*stk_new(int cap);
void	*stk_del(t_stk *stk);
void	stk_push(t_stk *stk, int val);
int		stk_pop(t_stk *stk);
int		stk_getpos(t_stk *stk, int pos);

t_stk	*stk_new(int cap)
{
	t_stk	*res;

	res = (t_stk *)ft_calloc(1, sizeof(t_stk));
	if (!res)
		return (NULL);
	res->cap = cap;
	res->top = -1;
	res->dat = (int *)ft_calloc(cap, sizeof(int));
	if (!res->dat)
		return (stk_del(res));
	return (res);
}

void	*stk_del(t_stk *stk)
{
	free(stk->dat);
	free(stk);
	return (NULL);
}

void	stk_push(t_stk *stk, int val)
{
	if (stk->top == stk->cap - 1)
	{
		ft_printf("Err: Overflow!\n");
		return ;
	}
	stk->dat[++stk->top] = val;
}

int	stk_pop(t_stk *stk)
{
	if (stk->top < 0)
	{
		ft_printf("Err: Underflow!\n");
		return (0);
	}
	return (stk->dat[stk->top--]);
}

int	stk_getpos(t_stk *stk, int pos)
{
	if (pos < 0 || pos > stk->top)
	{
		ft_printf("Err: NaN pos!\n");
		return (0);
	}
	return (stk->dat[stk->top - pos]);
}
