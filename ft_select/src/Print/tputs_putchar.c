/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs_putchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:39:24 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:02:34 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"

/*
** Function used by tputs.
** Why STDERR?
** I'm not sure, but, when I call echo `./ft_select op1 op2` and
** write everyhing on STDIN (ft_printf("op1\n op2")), nothing in
** ft_select would be printed.
**
** Generally, we print to stdin only when we want to print the result.
*/

int		tputs_putchar(int c)
{
	write(FD_WR, &c, 1);
	return (1);
}
