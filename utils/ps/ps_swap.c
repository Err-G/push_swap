/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:03:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/06 15:42:19 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_ps *ps);
void	ps_sb(t_ps *ps);
void	ps_ss(t_ps *ps);

void	ps_sa(t_ps *ps)
{
	if (ps->a->top < 1)
		return ;
	stack_swap(ps->a);
}

void	ps_sb(t_ps *ps)
{
	if (ps->b->top < 1)
		return ;
	stack_swap(ps->b);
}

void	ps_ss(t_ps *ps)
{
	ps_sa(ps);
	ps_sb(ps);
}
