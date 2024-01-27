/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:24:11 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/26 22:27:26 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_ps *ps);
void	ps_rb(t_ps *ps);
void	ps_rr(t_ps *ps);

void	ps_ra(t_ps *ps)
{
	rot(ps->a);
}

void	ps_rb(t_ps *ps)
{
	rot(ps->b);
}

void	ps_rr(t_ps *ps)
{
	rot(ps->a);
	rot(ps->b);
}
