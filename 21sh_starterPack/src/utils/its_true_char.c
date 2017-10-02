/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_true_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:42:27 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:04:37 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** Controlls if a given character address is between 'quotes' or is \$
** or "\$".
*/

int		its_true_char(char *context, char *c_addr)
{
	char	oppended_quote;

	oppended_quote = 0;
	while (*context)
	{
		if (*context == '\\' && oppended_quote != '\'')
		{
			context++;
			if (context == c_addr)
				return (0);
		}
		else if (ft_strchr("'\"", *context))
		{
			if (oppended_quote == 0 || oppended_quote == *context)
			{
				oppended_quote = (oppended_quote == 0) ? (*context) : (0);
				context++;
			}
		}
		if (context == c_addr && oppended_quote == '\'')
			return (0);
		context++;
	}
	return (1);
}
