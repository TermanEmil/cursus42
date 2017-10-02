/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:58:46 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 16:26:56 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

void		ft_tputs(char *attr_name)
{
	char	*str_attr;

	if ((str_attr = tgetstr(attr_name, NULL)) == NULL)
	{
		ft_fprintf(STDERR, "%s: doesn't support %s attribute\n",
			PRJ_NAME, attr_name);
		exit(EXIT_FAILURE);
	}
	tputs(str_attr, 1, &tputs_putchar);
}
