/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:39:24 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/13 15:55:51 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_init(int ac, char **av)
{
	t_ps	*res;
	t_stack	*stk;
	int		err;

	res = ps_new(ft_count_args(ac, av));
	err = ft_get_args(&stk, ac, av);
	if (!stk || !res)
	{
		stack_del(stk);
		ps_del(res);
		return (NULL);
	}
	err += ft_check_dup(stk);
	if (err)
	{
		stack_del(stk);
		ps_del(res);
		ft_printf("Error\n");
		return (NULL);
	}
	while (stk->top >= 0)
		stack_push(res->a, stack_pop(stk));
	stack_del(stk);
	return (res);
}
