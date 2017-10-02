/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_goto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:13:10 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 16:32:22 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

void		cursor_goto(int x, int y)
{
	char		*str;
	
	if ((str = tgetstr("cm", NULL)) == NULL)
		ft_proj_err("doesn't support cm attribute", 1);
	if ((str = tgoto(str, x, y)) == NULL)
		ft_proj_err("can't move cursor, perhaps your pc doesn't"
			" support tgoto", 1);
	tputs(str, 1, &tputs_putchar);
}
