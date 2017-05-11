/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:52:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 10:04:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

void			populate_oldpwd(char **old_pwd)
{
	char	*env_oldpwd;

	if ((env_oldpwd = environ_getvalue("OLDPWD")))
		*old_pwd = ft_strdup(env_oldpwd);
	else
		*old_pwd = ft_strnew(0);
}

int				can_move_to_dir(char *dirpath)
{
	int	ret;

	if ((ret = access(dirpath, F_OK)))
		ft_putendl_fd("cd: No such file or directory", 2);
	else if ((ret = access(dirpath, X_OK)))
		ft_putendl_fd("cd: Access denied", 2);
	return (!ret);
}

int				builtin_cd(char **av)
{
	char	*dir;
	char	*current_dir;
	char	*old_pwd;

	current_dir = getcwd(NULL, 0);
	populate_oldpwd(&old_pwd);
	if (av[0] && av[1])
	{
		if (ft_strequ(av[1], "-") && *old_pwd != 0)
		{
			can_move_to_dir(old_pwd) ? chdir(old_pwd) : 0;
			ft_putendl(old_pwd);
		}
		else
			can_move_to_dir(av[1]) ? chdir(av[1]) : 0;
	}
	else if ((dir = environ_getvalue("HOME")))
		can_move_to_dir(dir) ? chdir(dir) : 0;
	else
		ft_putendl("cd: HOME is not set");
	if (current_dir && !ft_strequ(old_pwd, current_dir))
		environ_setvalue("OLDPWD", current_dir);
	current_dir ? free(current_dir) : (void)0;
	free(old_pwd);
	return (0);
}
