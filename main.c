/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:50:15 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 15:45:25 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*ps;
	int		stk_size;

	if (ac < 2)
		return (0);
	ps = ft_init(ac, av);
	if (!ps)
		return (0);
	stk_size = ps->a->top + 1;
	if (stk_size >= 1 && stk_size <= 3)
		sort_less(ps);
	//ps_print(ps);
	ps_del(ps);
	return (0);
}
