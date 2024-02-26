/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:50:15 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:57:40 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*ps;

	if (ac < 2)
		return (0);
	ps = ft_init(ac, av);
	if (!ps)
		return (0);
	sort(ps);
	ps_print(ps);
	ps_del(ps);
	return (0);
}
