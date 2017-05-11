/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:53:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/14 13:52:21 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>
#include <shell/shell.h>

int				builtin_setenv(char **av)
{
	size_t	ac;

	ac = arg_count(av);
	if (ac == 3)
	{
		environ_setvalue(av[1], av[2]);
	}
	return (0);
}
