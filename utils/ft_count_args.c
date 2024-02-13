/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:40:32 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/13 15:40:33 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_args(int ac, char **av)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (++i < ac)
		wc += ft_wordcount(av[i], " \n");
	return (wc);
}
