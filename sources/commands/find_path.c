/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:20:38 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/07 14:09:37 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <environ/environ.h>
#include <commands/commands.h>

char		**get_paths(void)
{
	char	*envpath;

	if ((envpath = environ_getvalue("PATH")))
		return (ft_strsplit(envpath, ':'));
	else
		return (ft_memalloc(sizeof(char **)));
}

char		*add_pathcomponents(char *a, char *b)
{
	char	*path;
	size_t	len;

	len = ft_strlen(a);
	if (a[len - 1] == '/')
	{
		path = ft_strnew(ft_strlen(a) + ft_strlen(b));
		ft_strcpy(path, a);
	}
	else
	{
		path = ft_strnew(len + ft_strlen(b));
		ft_strcpy(path, a);
		path[len] = '/';
	}
	ft_strcat(path, b);
	return (path);
}

int			find_path(char **name)
{
	char	**paths;
	char	*path;
	size_t	i;

	paths = get_paths();
	i = 0;
	while (paths[i] != 0)
	{
		path = add_pathcomponents(paths[i], *name);
		if (bin_exists(path))
		{
			free(*name);
			*name = path;
			return (1);
		}
		i += 1;
	}
	return (0);
}
