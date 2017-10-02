/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:36:32 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:29:35 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

pid_t	g_current_process;

void	display_prompt(void)
{
	ft_putstr("$> ");
}

void 	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		if (g_current_process == 0)
			display_prompt();
	}
}

/*
** echo () --- wtf ?
** echo $'la' $(pwd)
** $0 $? $# $@
*/

int		main(void)	
{
	t_sh	sh_data;
	char	*cmd_line;
	char	**args;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_fprintf(STDERR, "\ncan't catch SIGINT\n");
	env_init(&sh_data);
	init_cmd_dex(&sh_data);
	while (1)
	{
		display_prompt();
		cmd_line = read_cmd();
		process_dolar_values(&cmd_line, &sh_data);
		args = extract_all_arguments(cmd_line);
		execute_cmd(args, &sh_data);
		ft_strdelif(&cmd_line);
		ft_free_bidimens(args);
	}
	env_destroy(&sh_data);
	ft_lstdel(&(sh_data.cmd_history), &del_strlist_cell);
}
