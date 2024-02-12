/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:01 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/06 15:41:56 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_ps *ps);
void	ps_pb(t_ps *ps);

void	ps_pa(t_ps *ps)
{
	if (ps->b->top < 0)
		return ;
	stack_push(ps->a, stack_pop(ps->b));
}

void	ps_pb(t_ps *ps)
{
	if (ps->a->top < 0)
		return ;
	stack_push(ps->b, stack_pop(ps->a));
}
