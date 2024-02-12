/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/06 15:41:47 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ps_new(int capacity)
{
	t_ps	*res;

	res = (t_ps *)ft_calloc(1, sizeof(t_ps));
	res->a = stack_new(capacity);
	res->b = stack_new(capacity);
	if (!res->a || !res->b)
	{
		if (res->a)
			free(res->a);
		if (res->b)
			free(res->b);
		free(res);
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
