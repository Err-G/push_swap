/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:28:14 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/06 15:42:04 by ecarvalh         ###   ########.fr       */
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
	stack_rrot(ps->a);
}

void	ps_rrb(t_ps *ps)
{
	if (ps->b->top < 1)
		return ;
	stack_rrot(ps->b);
}

void	ps_rrr(t_ps *ps)
{
	ps_rra(ps);
	ps_rrb(ps);
}
