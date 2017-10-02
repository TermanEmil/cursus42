#include "shell42.h"
#include "unittest.h"
#include <fcntl.h>
#include "ft_key_codes.h"
#include <time.h>

t_shdata		g_shdata;
t_shinput		*g_shinput;
t_current_input	*g_current_in;



void	shlogic_exec(t_list *lst_of_words)
{
	//-	Process dollar values
	//-	Process tilda value ~

	//- Divide in subcommands: ; | `` > >> < <<

	//-	Find what command it is:
	//		is it referring to a specific pointed program?
	//		is it a built in cmd?
	//		is it a program from PATH?
	//		
	//
}

/*
** When I finish:
**
** 1) termcap `ei' in shell_read_user_input(). When exit, restore this value to
** what it was.
*/

int		main(void)
{
	init_shell();

	ft_putstr("42sh shell by eterman");
	term_putnewl();
	input_reprint_here(g_current_in);

	while (1)
	{
		shinput_reset_signals(g_shinput);
		shell_read_user_input();
		shinput_process_signals(g_shinput);
	}
	event_exit(0);
}

/*
	to do:
	1) History
		ctrl-R
		!

	2) Globbing (wild cards: * ? [] {} etc.)

	3) When I copy paste code on multiple lines, it doesn't really work
	That's because I don't process each key right away
	(see shell_read_user_input)
*/