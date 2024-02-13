/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/13 15:04:02 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ps_new(int capacity)
{
	t_ps	*res;

	res = (t_ps *)ft_calloc(1, sizeof(t_ps));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	res->a = stack_new(capacity);
	res->b = stack_new(capacity);
	if (!res->a || !res->b)
	{
		ps_del(res);
		return (NULL);
	}
	return (res);
}

void	ps_del(t_ps *ps)
{
	stack_del(ps->a);
	stack_del(ps->b);
	free(ps);
}