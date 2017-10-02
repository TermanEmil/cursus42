/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:38:35 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 08:40:57 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		destroy_select_data(t_select *data)
{
	ft_lstdel(&(data->options), &ft_lst_memdel);
}

void			setup_terminal(void)
{
	char	*terminal_name;

	if (!(terminal_name = getenv("TERM")))
		ft_proj_err("couldn't get terminal name. Enviroment->TERM"
			" is not set", 1);
	if (tgetent(NULL, terminal_name) <= 0)
		ft_proj_err("Terminal name (enviroment->TERM)"
			" couldn't be recognized", 1);
	full_screen(1);
	cursor_on(0);
	cursor_goto(0, 0);
	echo_off();
}

int				main(int argc, char **argv)
{
	t_select	data;

	if (argc < 2)
	{
		ft_putstr_fd("ft_select: usage: ft_select op1 op2 op3\n", 2);
		exit(0);
	}
	if (ft_strequ(argv[1], "-h") || ft_strequ(argv[1], "--help"))
	{
		print_help_text(1);
		exit(0);
	}
	ft_bzero(&data, sizeof(t_select));
	init_select_data(&data, argc, argv);
	listen_to_signals();
	setup_terminal();
	refresh_output();
	while (1)
		if (process_input(&data) == 1)
			break ;
	ft_clear_screen();
	term_restore();
	print_selected(data.options, 1);
	destroy_select_data(&data);
	return (0);
}
