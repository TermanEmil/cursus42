/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_function_in_dex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:20:22 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:41:12 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** Returns the function of the first occurance from sh_data->cmd_dex with
** cmd_name.
*/

t_cmd_fun 	find_function_in_dex(char *cmd_name, t_sh *sh_data)
{
	t_list	*aux;

	aux = sh_data->cmd_dex;
	while (aux)
	{
		if (ft_strequ(cmd_name, LCONT(aux, t_cmd_key*)->cmd))
			return (LCONT(aux, t_cmd_key*)->key);
		aux = LNEXT(aux);
	}
	return (NULL);
}
