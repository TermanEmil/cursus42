/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dolar_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:51:35 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:15:05 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** The main dolar processor.
**
** There are more things about '$'.
** wasdrlnul == dolar was null.
*/

void	process_dolar_values(char **str_addr, t_sh *sh_data)
{
	char	*dolar;
	int		wasdlrnul;

	if (str_addr == NULL || *str_addr == NULL)
		return ;
	dolar = NULL;
	wasdlrnul = 0;
	while ((dolar = ft_strchr((dolar) ? (dolar + !wasdlrnul) : *str_addr, '$')))
	{
		if (its_true_char(*str_addr, dolar))
		{
			if (process_dolar_envir(str_addr, &dolar, sh_data))
				wasdlrnul = 0;
			else
				wasdlrnul = process_dolar_null(dolar);
		}
	}
}
