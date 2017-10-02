/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:34:15 by eterman           #+#    #+#             */
/*   Updated: 2017/01/17 10:00:25 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	env_destroy(t_sh *sh_data)
{
	if (sh_data->env.env_list != NULL)
		ft_lstdel(&(sh_data->env.env_list), &del_strlist_cell);
	ft_free_bidimens(sh_data->env.env_table);
}
