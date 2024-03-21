/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:14:16 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/25 17:20:02 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*stk_new(int cap);
void	*stk_del(t_stk *stk);
void	stk_push(t_stk *stk, int val);
int		stk_pop(t_stk *stk);
void	stk_print(t_stk *stk);

t_stk	*stk_new(int cap)
{
	t_stk	*res;

	res = (t_stk *)ft_calloc(1, sizeof(t_stk));
	if (!res)
		return (NULL);
	res->cap = cap;
	res->top = 0;
	res->dat = (int *)ft_calloc(cap, sizeof(int));
	if (!res->dat)
		return (stk_del(res));
	return (res);
}

void	*stk_del(t_stk *stk)
{
	if (stk)
		free(stk->dat);
	free(stk);
	return (NULL);
}

void	stk_push(t_stk *stk, int val)
{
	if (stk->top == stk->cap)
	{
		ft_printf("Err: Overflow!\n");
		return ;
	}
	stk->dat[stk->top++] = val;
}

int	stk_pop(t_stk *stk)
{
	if (!stk->top)
	{
		ft_printf("Err: Underflow!\n");
		return (0);
	}
	return (stk->dat[--stk->top]);
}

void	stk_print(t_stk *stk)
{
	int	i;

	if (!stk->top)
		return ;
	i = -1;
	while (++i < stk->top - 1)
		ft_printf("%d ", stk_getpos(stk, i));
	ft_printf("%d", stk_getpos(stk, i));
}
