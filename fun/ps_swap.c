/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:03:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/26 22:27:39 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_ps *ps);
void	ps_sb(t_ps *ps);
void	ps_ss(t_ps *ps);

void	ps_sa(t_ps *ps)
{
	swap(ps->a);
}

void	ps_sb(t_ps *ps)
{
	swap(ps->b);
}

void	ps_ss(t_ps *ps)
{
	swap(ps->a);
	swap(ps->b);
}
