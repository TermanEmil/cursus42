/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:08:21 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:36:41 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*process_rgb_cl_text(char *clr, char *buff)
{
	if (ft_strstr(clr, "rgb"))
	{
		if (ft_strnequ(clr, "bg_", 3))
			return (rgb_color(ft_atoi(clr + 6), 0, buff));
		else
			return (rgb_color(ft_atoi(clr + 3), 1, buff));
	}
	else
		ft_strcpy(buff, CL_EOC);
	return (buff);
}

void			print_color(char *clr)
{
	char	buff[30];

	if (clr != NULL)
	{
		if (ft_strstr(clr, "rgb"))
		{
			ft_putstr(process_rgb_cl_text(clr, buff));
		}
		else
		{
			ft_putstr("\x1B[");
			ft_putstr(clr);
			ft_putstr("m");
		}
	}
}
