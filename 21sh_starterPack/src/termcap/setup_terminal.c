/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 09:28:43 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 16:46:06 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

void			setup_terminal(void)
{
	char		*terminal_name;

	if (!(terminal_name = getenv("TERM")))
		ft_proj_err("couldn't get terminal name. Enviroment->TERM"
			" is not set", 1);
	if (tgetent(NULL, terminal_name) <= 0)
		ft_proj_err("Terminal name (enviroment->TERM)"
			" couldn't be recognized", 1);
	echo_off();
}
