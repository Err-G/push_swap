/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:28:14 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/26 22:29:41 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_ps *ps);
void	ps_rrb(t_ps *ps);
void	ps_rrr(t_ps *ps);

void	ps_rra(t_ps *ps)
{
	rrot(ps->a);
}

void	ps_rrb(t_ps *ps)
{
	rrot(ps->b);
}

void	ps_rrr(t_ps *ps)
{
	rrot(ps->a);
	rrot(ps->b);
}
