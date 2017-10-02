/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_to_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:57:33 by eterman           #+#    #+#             */
/*   Updated: 2017/05/15 11:01:57 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** SIG_DFL stands for "do the default thing".
** The thing with ioctl here: sends the suspend character to terminal.
*/

static void	handle_suspend_and_cont(int signum)
{
	char	buf[2];

	if (!isatty(1))
		return ;
	if (signum == SIGTSTP)
	{
		buf[0] = get_select_data(NULL)->old_term.c_cc[VSUSP];
		buf[1] = 0;
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, buf);
		ft_clear_screen();
		term_restore();
	}
	else
	{
		listen_to_signals();
		setup_terminal();
		refresh_output();
	}
}

static void	handle_signal(int signum)
{
	if (signum == SIGWINCH)
		refresh_output();
	else
	{
		ft_clear_screen();
		term_restore();
		exit(0);
	}
}

void		listen_to_signals(void)
{
	int		i;

	if (signal(SIGTSTP, &handle_suspend_and_cont) == SIG_ERR)
		ft_proj_err("can't listen to SIGTSTP", 1);
	if (signal(SIGCONT, &handle_suspend_and_cont) == SIG_ERR)
		ft_proj_err("can't listen to SIGCONT", 1);
	if (signal(SIGWINCH, &handle_signal) == SIG_ERR)
		ft_proj_err("can't listen to SIGWINCH", 1);
	i = 0;
	while (i < 32)
	{
		if (i != SIGKILL && i != SIGSTOP && i != SIGCHLD && i != SIGCONT &&
			i != SIGURG && i != SIGIO && i != SIGWINCH && i != SIGTSTP)
			signal(i, &handle_signal);
		i++;
	}
}
