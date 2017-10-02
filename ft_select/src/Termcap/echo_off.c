/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_off.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:06:40 by eterman           #+#    #+#             */
/*   Updated: 2017/02/18 20:06:44 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Each character is processed char by char, it doesn't wait for a newline,
** this does ICANON.
** With ECHO, I turn character echoing off.
** It uses the static select_data from get_select_data(NULL).
*/

void		echo_off(void)
{
	t_termios	term;

	if (tcgetattr(STDIN, &term) < 0)
		ft_proj_err("couldn't read terminal data", 1);
	get_select_data(NULL)->old_term = term;
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN, TCSADRAIN, &term) < 0)
		ft_proj_err("couldn't change terminal settings", 1);
}
