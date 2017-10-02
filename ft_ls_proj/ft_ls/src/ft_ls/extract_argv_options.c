/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_argv_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:07:05 by eterman           #+#    #+#             */
/*   Updated: 2017/01/03 14:38:05 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define INVALID_OPTION_MSG "ls: invalid option -- '%c'\n"

static void	add_ls_option(t_ls_data *ls_data, char option)
{
	if (ft_strchr(ls_data->options, option) == NULL)
		ls_data->options[ft_strlen(ls_data->options)] = option;
}

/*
** Returns -1 if an error has occured; 1 if it successfully extracted options
** and 0 if it's a name of a file.
*/

static int	extract_options(char *command, t_ls_data *ls_data)
{
	if (its_option_field(command))
	{
		command++;
		while (*command && ft_strchr("lRartufUgdGe", *command))
		{
			add_ls_option(ls_data, *command);
			command++;
		}
		if (*command != 0)
		{
			ft_fprintf(FT_STDERR, INVALID_OPTION_MSG, *command);
			return (-1);
		}
		return (1);
	}
	return (0);
}

int			extract_argv_options(t_ls_data *ls_data, int *valid_argv)
{
	int		i;
	int		value;

	i = 1;
	while (i < ls_data->argc)
	{
		value = extract_options(ls_data->argv[i], ls_data);
		if (value == -1)
			return (-1);
		if (value == 0)
			valid_argv[i] = 1;
		i++;
	}
	if (ft_strchr(ls_data->options, 'f'))
	{
		add_ls_option(ls_data, 'a');
		add_ls_option(ls_data, 'U');
	}
	if (ft_strchr(ls_data->options, 'g'))
		add_ls_option(ls_data, 'l');
	return (0);
}
