/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:06:30 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/20 13:08:23 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_ps *ps);
void	ps_rrb(t_ps *ps);
void	ps_rrr(t_ps *ps);

void	ps_rra(t_ps *ps)
{
	if (ps->a->top < 1)
		return ;
	stk_rrot(ps->a);
}

void	ps_rrb(t_ps *ps)
{
	if (ps->b->top < 1)
		return ;
	stk_rrot(ps->b);
}

void	ps_rrr(t_ps *ps)
{
	ps_rra(ps);
	ps_rrb(ps);
}
