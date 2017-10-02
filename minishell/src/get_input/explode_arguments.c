/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explode_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:53:00 by eterman           #+#    #+#             */
/*   Updated: 2017/01/16 13:12:40 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** Moves every char with n positions on left.
** Make sure you give a valid str and n.
*/

static void	move_string_to_left(char *str, int n)
{
	int		i;

	i = 0;
	while (str[i + n])
	{
		str[i] = str[i + n];
		i++;
	}
	str[i] = 0;
}

/*
** The main part.
** Returns a fresh string from cmd, properly processed (' " \)
*/

char	*get_first_arg(char *cmd)
{
	int		i;
	char	oppended_quote;
	char	*result;

	oppended_quote = 0;
	i = -1;
	while (cmd[++i])
		if (ft_strchr(SHELL_DELIMS, cmd[i]) && oppended_quote == 0)
			break ;
		else if (oppended_quote != '\'' && cmd[i] == '\\')
			move_string_to_left(cmd + i, 1 + (cmd[i + 1] == '\n'));
		else if (ft_strchr("\"'", cmd[i]))
		{
			if (oppended_quote == 0 || oppended_quote == cmd[i])
			{
				oppended_quote = (oppended_quote == 0) ? (cmd[i]) : (0);
				move_string_to_left(cmd + i, 1);
				i--;
			}
		}
	if ((result = ft_strndup(cmd, i)) == NULL)
		ft_error_mem();
	return (result);
}

/*
** Realocating the memory each time, is bad.
*/

void	add_slots(char ***buff, int *slots)
{
	char	**new_buff;
	int		i;

	*slots = (*slots == 0) ? (16) : (*slots * 2);
	new_buff = (char**)malloc(sizeof(char**) * (*slots) + 1);
	i = 0;
	if (*buff != NULL)
	{
		while ((*buff)[i])
		{
			new_buff[i] = (*buff)[i];
			i++;
		}
		free(*buff);
	}
	new_buff[i] = NULL;
	*buff = new_buff;
}

/*
** Just to be sure...
*/

void	jump_over_delimiters(char **str)
{
	while (**str && ft_strchr(SHELL_DELIMS, **str))
		(*str)++;
}

/*
** Recursively extracts all arguments.
** Slots stands for 'how big is buff'.
*/

void	rec_extract(char *cmd, char ***buff, int i, int slots)
{
	if (i >= slots)
		add_slots(buff, &slots);
	if (cmd != NULL)
	{
		jump_over_delimiters(&cmd);
		if (cmd[0] != 0)
		{
			(*buff)[i] = get_first_arg(cmd);
			(*buff)[i + 1] = NULL;
			rec_extract(cmd + ft_strlen((*buff)[i]), buff, i + 1, slots);
		}
	}
}

/*
** It handles the quotes and the '\' symbol.
*/

char	**extract_all_arguments(char *cmd)
{
	char	**result;

	if (cmd == NULL || cmd[0] == 0)
		return (NULL);
	result = NULL;
	rec_extract(cmd, &result, 0, 0);
	return (result);
}
