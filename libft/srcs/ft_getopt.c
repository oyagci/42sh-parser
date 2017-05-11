/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:59:43 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 13:12:17 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_getopt.h"

char	*g_optarg = 0;
int		g_optind = 1;
int		g_opterr = 1;
int		g_optopt = 0;
int		g_optreset = 0;

int			illegal_option(char *name, char c)
{
	if (g_opterr == 1)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("usage: ", 2);
		ft_putendl_fd("env [-i]", 2);
		ft_putendl_fd("\t[name=value]", 2);
	}
	return (-1);
}

int			isopt(char c, char *optstring)
{
	if (ft_strchr(optstring, c))
		return (c);
	else
		return (0);
}

void		set_reset(int *is_over)
{
	if (g_optreset == 1)
	{
		*is_over = 0;
		g_optind = 1;
		g_optreset = 0;
	}
}

int			ft_getopt(int argc, char *argv[], char *optstring)
{
	static int	is_over = 0;
	static int	i = 1;

	set_reset(&is_over);
	if (is_over == 1)
		return (-1);
	if (g_optind < argc && argv[g_optind][0] == '-' && argv[g_optind][1] != '-')
	{
		if ((g_optopt = isopt(argv[g_optind][i], optstring)))
		{
			if (argv[g_optind][++i] == 0)
			{
				i = 1;
				g_optind++;
			}
			return (g_optopt);
		}
		else
			return (illegal_option(argv[0], argv[g_optind][i]));
	}
	(g_optind < argc && argv[g_optind][0] == '-' && argv[g_optind][1] == '-') ?
		g_optind += 1 : 0;
	is_over = 1;
	return (-1);
}
