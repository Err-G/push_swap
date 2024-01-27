/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:01 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/26 22:27:55 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_ps *ps);
void	ps_pb(t_ps *ps);

void	ps_pa(t_ps *ps)
{
	push(ps->a, pop(ps->b));
}

void	ps_pb(t_ps *ps)
{
	push(ps->b, pop(ps->a));
}
