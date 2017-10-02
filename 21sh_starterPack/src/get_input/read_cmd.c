/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:11:21 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:33:53 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static int	is_complete_cmd(char *cmd)
{
	int		i;
	int		oppended_quote;

	if (cmd == NULL)
		return (-3);
	oppended_quote = 0;
	i = -1;
	while (cmd[++i])
	{
		if (oppended_quote != '\'' && cmd[i] == '\\')
		{
			if (cmd[i + 1] == 0)
				return (-1);
			else
				i++;
		}
		else if (ft_strchr("\"'", cmd[i]))
		{
			if (oppended_quote == 0 || oppended_quote == cmd[i])
				oppended_quote = (oppended_quote == 0) ? (cmd[i]) : (0);
		}
	}
	return ((oppended_quote == 0) ? (0) : (-2));
}

static char	*read_input(void)
{
	char	*buff;
	int		ret;

	buff = NULL;
	ret = get_next_line(STDIN, &buff);
	if (ret == -1)
		ft_error_mem();
	else if (ret == -2)
		ft_big_error("Can't read from standard input");	
	return (buff);
}

char		*read_cmd(void)
{
	char	*buff;
	int		ret;

	buff = read_input();
	while ((ret = is_complete_cmd(buff)) < 0)
	{
		ft_putstr("> ");
		ft_str3concat(&buff, "\n", read_input());
	}
	return (buff);
}
