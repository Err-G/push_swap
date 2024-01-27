/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:35:54 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/27 13:15:22 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_ps	ps;

	if (ac < 2)
		return (0);
	ps.a = stack_new(ac - 1);
	ps.b = stack_new(ac - 1);
	i = -1;
	while (++i < ac - 1)
		push(ps.a, ft_strtoi(av[i + 1]));
	stack_print(ps.a, "a");
	return (0);
}
