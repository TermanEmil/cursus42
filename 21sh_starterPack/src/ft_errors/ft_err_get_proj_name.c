/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_get_proj_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:08:16 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 18:24:27 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Saves the project name in a static variable, so that I can call it
** for my ft_error functions.
** Ex: minishell: not enough space
*/

char		*ft_err_get_proj_name(char *proj_name)
{
	static char		*name;

	if (proj_name)
		name = proj_name;
	return (name);
}

void		ft_err_init_proj_name(char *proj_name)
{
	ft_err_get_proj_name(proj_name);
}
