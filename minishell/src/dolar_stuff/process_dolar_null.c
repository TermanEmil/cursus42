/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dolar_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:44:47 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:13:27 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static int	dolar_remains(char *dolar)
{
	if (dolar[1] == 0)
		return (1);
	if (ft_strchr("\"'", dolar[1]) == NULL)
	{
		return (!ft_isalnum(dolar[1]));
	}
	else
		return (0);
}

/*
** Processs the case when nothing was assigned with '$'.
*/

int		process_dolar_null(char *dolar)
{
	int		i;
	int		len;

	if (dolar_remains(dolar))
		return (0);
	i = 1;
	while (dolar[i])
	{
		if (!ft_isalnum(dolar[i]))
			break ;
		i++;
	}
	len = ft_strlen(dolar + i);
	ft_memmove((void*)(dolar), (void*)(dolar + i), len);
	dolar[len] = 0;
	return (1);
}
