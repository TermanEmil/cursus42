/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_nul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:11:41 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:30:21 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Just a strncpy which puts a null byte at the end
*/

void	ft_strncpy_nul(char *dest, char *src, size_t len)
{
	ft_strncpy(dest, src, len);
	dest[len] = 0;
}
