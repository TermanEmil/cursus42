/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_restore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:02:01 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 01:13:46 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Changes only those parameters, which were changed by this program.
** I could set tcsetattr(STDIN, TCSANOW, old_term) but what if the user
** managed to change few parameters while the program was running?
** It uses the static select_data from get_select_data(NULL).
*/

void		term_restore(void)
{
	t_termios	*old_term;
	t_termios	term;

	old_term = &((get_select_data(NULL))->old_term);
	if (tcgetattr(STDIN, &term) < 0)
		ft_proj_err("couldn't read terminal data", 1);
	term.c_lflag |= old_term->c_lflag & ECHO;
	term.c_lflag |= old_term->c_lflag & ICANON;
	term.c_cc[VMIN] = old_term->c_cc[VMIN];
	term.c_cc[VTIME] = old_term->c_cc[VTIME];
	if (tcsetattr(STDIN, TCSADRAIN, &term) < 0)
		ft_proj_err("couldn't change terminal settings", 1);
	cursor_on(1);
	full_screen(0);
}
