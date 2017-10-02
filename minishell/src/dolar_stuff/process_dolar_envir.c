/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dolar_envir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:46:58 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:11:38 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** Processes dolar values for enviroment variables.
** dlr == dolar_address
*/

int		process_dolar_envir(char **str_addr, char **dolar, t_sh *sh_data)
{
	char	*env_value;
	size_t	len;

	if ((env_value = get_env_value(*dolar + 1, sh_data, &len)) != NULL)
	{
		insert_val_at_dolar(str_addr, env_value, *dolar, len);
		*dolar = *str_addr + ft_strlen(env_value);
		return (1);
	}
	return (0);
}
