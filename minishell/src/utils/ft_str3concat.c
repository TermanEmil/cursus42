/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:13:02 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:31:42 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3concat(char **dest, char *s1, char *s2)
{
	char	*tmp;

	if (dest == NULL || *dest == NULL || s1 == NULL)
		return (NULL);
	tmp = ft_strmegajoin(3, *dest, s1, s2);
	ft_strdelif(dest);
	*dest = tmp;
	return (*dest);
}
