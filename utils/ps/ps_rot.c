/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:24:11 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/06 15:42:12 by ecarvalh         ###   ########.fr       */
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
	stack_rot(ps->a);
}

void	ps_rb(t_ps *ps)
{
	if (ps->b->top < 1)
		return ;
	stack_rot(ps->b);
}

void	ps_rr(t_ps *ps)
{
	ps_ra(ps);
	ps_rb(ps);
}
