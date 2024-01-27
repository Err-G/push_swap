/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:28:03 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/27 20:46:01 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strtoi(char *str, int *error)
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
	if (!ft_isdigit(str[i]))
		return (*error++);
	while (ft_isdigit(str[i]))
	{
		if (res >= 214748364 && (str[i] - '0') > 7)
			return (*error++);
		res = (res * 10) + (str[i++] - '0');
	}
	return (res * sig);
}
