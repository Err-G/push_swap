/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:57:57 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/24 21:59:56 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_ps *ps);
void	ps_pb(t_ps *ps);
void	ps_sa(t_ps *ps);
void	ps_sb(t_ps *ps);
void	ps_ss(t_ps *ps);

void	ps_pa(t_ps *ps)
{
	if (!ps->b->top)
		return ;
	stk_push(ps->a, stk_pop(ps->b));
}

void	ps_pb(t_ps *ps)
{
	if (!ps->a->top)
		return ;
	stk_push(ps->b, stk_pop(ps->a));
}

void	ps_sa(t_ps *ps)
{
	if (ps->a->top < 2)
		return ;
	stk_swap(ps->a);
}

void	ps_sb(t_ps *ps)
{
	if (ps->b->top < 2)
		return ;
	stk_swap(ps->b);
}

void	ps_ss(t_ps *ps)
{
	ps_sa(ps);
	ps_sb(ps);
}
