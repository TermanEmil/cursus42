/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:03:55 by eterman           #+#    #+#             */
/*   Updated: 2017/02/12 17:29:45 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** If you use '| less' command on something, the text will be printed
** somewhere else, right? This does that job.
*/

void		full_screen(int yes)
{
	if (yes)
		ft_tputs("ti");
	else
		ft_tputs("te");
}
