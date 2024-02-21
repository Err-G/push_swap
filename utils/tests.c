/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:10:21 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 12:11:46 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		test_lth(int a, int b);
int		test_gth(int a, int b);
int		test_min(int a, int b);
int		test_max(int a, int b);

int	test_lth(int a, int b)
{
	return (a < b);
}

int	test_gth(int a, int b)
{
	return (a > b);
}

int	test_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	test_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
