/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_dex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:18:51 by eterman           #+#    #+#             */
/*   Updated: 2017/01/17 09:41:41 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static t_cmd_key	*new_cmd_key(char *cmd, t_cmd_fun fun)
{
	t_cmd_key	*result;

	if ((result = (t_cmd_key*)malloc(sizeof(t_cmd_key))) == NULL)
		return (NULL);
	result->cmd = cmd;
	result->key = fun;
	return (result);
}

static void			add_cmd_key(t_list **cmd_dex, char *cmd, t_cmd_fun fun)
{
	t_list		*cell;
	t_cmd_key	*cmd_key;

	if ((cmd_key = new_cmd_key(cmd, fun)) == NULL)
		ft_error_mem();
	if ((cell = ft_lstnew((void*)cmd_key, sizeof(t_cmd_key))) == NULL)
		ft_error_mem();
	ft_lstadd(cmd_dex, cell);
}

void	init_cmd_dex(t_sh *sh_data)
{
	t_list	*cmd_dex;

	cmd_dex = NULL;
	add_cmd_key(&cmd_dex, "exit", &execute_exit);
	add_cmd_key(&cmd_dex, "setenv", &execute_setenv);
	add_cmd_key(&cmd_dex, "unsetenv", &execute_unsetenv);
	add_cmd_key(&cmd_dex, "env", &execute_env);
	add_cmd_key(&cmd_dex, "cd", &execute_cd);
	sh_data->cmd_dex = cmd_dex;
}
