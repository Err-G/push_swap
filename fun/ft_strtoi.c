/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:28:03 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/27 13:45:12 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strtoi(char *str)
{
	unsigned int	i;
	unsigned int	res;
	int				sig;

	i = 0;
	res = 0;
	sig = 1;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (res >= 214748364 && (str[i] - '0') > 7)
		{
			ft_printf("Error\n");
			exit(1);
		}
		res = (res * 10) + (str[i++] - '0');
	}
	return (res * sig);
}
