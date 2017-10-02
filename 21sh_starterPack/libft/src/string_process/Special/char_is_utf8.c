/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_utf8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:57:27 by eterman           #+#    #+#             */
/*   Updated: 2017/05/29 18:01:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chars_are_folow_uni(const unsigned char *chars)
{
	while (*chars)
	{
		if ((*chars >> 6) != 0x2)
			return (0);
		chars++;
	}
	return (1);
}

int				char_is_utf8(const unsigned char *key)
{
	size_t		required_len;
	
	if (key[0] >> 7 == 0)
		required_len = 1;
	else if (key[0] >> 5 == 0x6)
		required_len = 2;
	else if (key[0] >> 4 == 0xE)
		required_len = 3;
	else if (key[0] >> 5 == 0x1E)
		required_len = 4;
	return (ft_strlen((char*)key) == required_len &&
		chars_are_folow_uni(key + 1));
}
