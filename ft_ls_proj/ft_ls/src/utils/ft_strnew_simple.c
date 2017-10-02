/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:37:59 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 18:03:29 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Just like ft_strnew, but doesn't call ft_bzero.
*/

char	*ft_strnew_simple(size_t size)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	*result = 0;
	return (result);
}
