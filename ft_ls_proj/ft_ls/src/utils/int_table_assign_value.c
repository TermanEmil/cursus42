/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_table_assign_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:58:53 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 21:18:43 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_table_assign_value(int *table, int value, int size)
{
	int		i;

	i = 0;
	while (i < size)
		table[i++] = value;
}
