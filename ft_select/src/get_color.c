/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:43:57 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 13:50:32 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colors.h"
#include <sys/stat.h>
#include "libft.h"
#include <stdarg.h>

static int		ft_str_multiend(char *arg, int argc, ...)
{
	va_list		ap;
	int			i;
	int			rs;

	va_start(ap, argc);
	rs = 0;
	i = 0;
	while (i < argc)
	{
		if (ft_strends_winth(arg, (char*)va_arg(ap, char*)))
		{
			rs = 1;
			break ;
		}
		i++;
	}
	va_end(ap);
	return (rs);
}

static char		*get_extension_color(char *arg)
{
	if (ft_str_multiend(arg, 4, ".c", ".h", ".py", ".cpp") ||
		ft_strequ(arg, "Makefile"))
		return (C_CODE);
	if (ft_str_multiend(arg, 5, ".o", ".a", ".zip", ".gz", ".rar") ||
		ft_match(arg, "*.tar*"))
		return (C_ARCHIVE);
	if (ft_str_multiend(arg, 10, ".png", ".jpeg", ".gif", ".bmp", ".pbm",
		".pgm", ".mp4v", ".wmv", ".mp4", ".mp3"))
		return (C_DISPLAY);
	return (NULL);
}

char			*get_color(char *arg)
{
	struct stat		buf;

	if (lstat(arg, &buf) < 0)
		return (NULL);
	if (S_ISDIR(buf.st_mode))
		return (C_DIR);
	if (S_ISFIFO(buf.st_mode))
		return (C_PIPE);
	if (S_ISBLK(buf.st_mode))
		return (C_BLOCK);
	if (S_ISCHR(buf.st_mode))
		return (C_CHRDEV);
	if (S_ISLNK(buf.st_mode))
		return (C_LINK);
	if (S_ISSOCK(buf.st_mode))
		return (C_SOCKET);
	if (buf.st_mode & S_IXUSR)
		return (C_EXEC);
	if (!(buf.st_mode & S_IRUSR))
		return (C_DENIED);
	return (get_extension_color(arg));
}
