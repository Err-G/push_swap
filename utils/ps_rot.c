/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:03:02 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/20 13:05:21 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_ps *ps);
void	ps_rb(t_ps *ps);
void	ps_rr(t_ps *ps);

void	ps_ra(t_ps *ps)
{
	if (ps->a->top < 1)
		return ;
	stk_rot(ps->a);
}

void	ps_rb(t_ps *ps)
{
	if (ps->b->top < 1)
		return ;
	stk_rot(ps->b);
}

void	ps_rr(t_ps *ps)
{
	ps_ra(ps);
	ps_rb(ps);
}
