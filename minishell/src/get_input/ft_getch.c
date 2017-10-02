/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:50:44 by eterman           #+#    #+#             */
/*   Updated: 2017/01/19 17:15:44 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

/*
** Source:
**		http://stackoverflow.com/questions/220818/detect-keyboard-event-in-c
** Inportant part:
** you can input ctr-shift-c without printing it and without stopping the prog,
*/

int		ft_rawgetch(void)
{
	struct termios	oldattr;
	struct termios	buf;
	int				ch;

	if (tcgetattr(FT_STDIN, &oldattr) < 0)
		return (-2);
	buf = oldattr;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	buf.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON);
	buf.c_cflag &= ~(CSIZE | PARENB);
	buf.c_cflag |= CS8;
	buf.c_oflag &= ~(OPOST);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &buf) < 0)
		return (-3);
	if (read(FT_STDIN, &ch, 1) < 0)
		return (-1);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &oldattr) < 0)
		return (-3);
	return (ch);
}

int		save_termios(struct termios *buf)
{
	if (tcgetattr(FT_STDIN, buf) < 0)
		return (-1);
	else
		return (0);
}

void	save_input_to_raw(struct termios buf)
{
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	buf.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON);
	buf.c_cflag &= ~(CSIZE | PARENB);
	buf.c_cflag |= CS8;
	buf.c_oflag &= ~(OPOST);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
}

/*
** Unfinished.
*/

int		load_termios(struct termios *buf)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, buf) < 0)
		return (-3);
	return (0);
}
