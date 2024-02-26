/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:10:21 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 00:39:05 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_lth(int a, int b);
int	_gth(int a, int b);
int	_equ(int a, int b);
int	_min(int a, int b);
int	_max(int a, int b);

int	_lth(int a, int b)
{
	return (a < b);
}

int	_gth(int a, int b)
{
	return (a > b);
}

int	_equ(int a, int b)
{
	return (a == b);
}

int	_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
