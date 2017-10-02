/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force_env_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:06:08 by eterman           #+#    #+#             */
/*   Updated: 2017/01/25 15:38:18 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	force_env_replace(char *env_name, char *env_value, t_sh *sh_data)
{
	char	*env_str;

	if (get_exact_env_val(env_name, sh_data) == NULL)
	{
		if ((env_str = ft_strmegajoin(3, env_name, "=", env_value)) == NULL)
			ft_error_mem();
		env_add_value(env_str, sh_data);
	}
	else
		env_replace(env_name, env_value, sh_data);
}
