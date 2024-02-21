/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:25:26 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 12:33:43 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_print(t_stk *stk);
void	stk_swap(t_stk *stk);
void	stk_rot(t_stk *stk);
void	stk_rrot(t_stk *stk);

void	stk_print(t_stk *stk)
{
	int	i;

	i = stk->top + 1;
	while (--i >= 0)
		ft_printf("%d ", stk->dat[i]);
	ft_printf("\n");
}

void	stk_swap(t_stk *stk)
{
	if (stk->top < 1)
	{
		ft_printf("Err: stk swap!\n");
		return ;
	}
	stk->dat[stk->top] ^= stk->dat[stk->top - 1];
	stk->dat[stk->top - 1] ^= stk->dat[stk->top];
	stk->dat[stk->top] ^= stk->dat[stk->top - 1];
}

void	stk_rot(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->top < 1)
	{
		ft_printf("Err: stk rot!\n");
		return ;
	}
	tmp = stk->dat[stk->top];
	i = stk->top + 1;
	while (--i)
		stk->dat[i] = stk->dat[i - 1];
	stk->dat[i] = tmp;
}

void	stk_rrot(t_stk *stk)
{
	int	tmp;
	int	i;

	if (stk->top < 1)
	{
		ft_printf("Err: stk rrot!\n");
		return ;
	}
	tmp = stk->dat[0];
	i = -1;
	while (++i < stk->top)
		stk->dat[i] = stk->dat[i + 1];
	stk->dat[i] = tmp;
}
