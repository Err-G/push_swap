/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:25:26 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:37:02 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stk_getpos(t_stk *stk, int pos);
void	stk_setpos(t_stk *stk, int pos, int val);
void	stk_swap(t_stk *stk);
void	stk_rot(t_stk *stk);
void	stk_rrot(t_stk *stk);

int	stk_getpos(t_stk *stk, int pos)
{
	if (!stk->top)
	{
		ft_printf("Err: getpos!\n");
		return (0);
	}
	pos = _abs(((stk->top - 1) - pos) % stk->top);
	return (stk->dat[pos]);
}

void	stk_setpos(t_stk *stk, int pos, int val)
{
	if (!stk->top)
	{
		ft_printf("Err: setpos!\n");
		return ;
	}
	pos = _abs(((stk->top - 1) - pos) % stk->top);
	stk->dat[pos] = val;
}

void	stk_swap(t_stk *stk)
{
	if (stk->top < 2)
	{
		ft_printf("Err: stk swap!\n");
		return ;
	}
	stk_setpos(stk, 0, stk_getpos(stk, 0) ^ stk_getpos(stk, 1));
	stk_setpos(stk, 1, stk_getpos(stk, 0) ^ stk_getpos(stk, 1));
	stk_setpos(stk, 0, stk_getpos(stk, 0) ^ stk_getpos(stk, 1));
}

void	stk_rot(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->top < 2)
	{
		ft_printf("Err: stk rot!\n");
		return ;
	}
	tmp = stk_getpos(stk, 0);
	i = -1;
	while (++i < stk->top - 1)
		stk_setpos(stk, i, stk_getpos(stk, i + 1));
	stk_setpos(stk, -1, tmp);
}

void	stk_rrot(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->top < 2)
	{
		ft_printf("Err: stk rrot!\n");
		return ;
	}
	tmp = stk_getpos(stk, -1);
	i = stk->top;
	while (--i)
		stk_setpos(stk, i, stk_getpos(stk, i - 1));
	stk_setpos(stk, 0, tmp);
}
