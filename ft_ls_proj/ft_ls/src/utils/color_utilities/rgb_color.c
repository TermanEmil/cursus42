/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:39:39 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 16:02:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes to buff a rgb color.
*/

char		*rgb_color(int cl, int is_text, char *buff)
{
	char		aux[20];

	if (cl < 0 || cl > 256)
	{
		*buff = 0;
		return (NULL);
	}
	ft_strcpy(buff, "\033[");
	ft_strcat(buff, ((is_text) ? "38" : "48"));
	ft_strcat(buff, ";5;");
	ft_strcat(buff, ft_bufitoa(cl, aux));
	ft_strcat(buff, "m");
	return (buff);
}
