/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:54:41 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/14 13:44:54 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell/shell.h>
#include <libft.h>

int				builtin_echo(char **av)
{
	size_t	ac;
	size_t	i;

	ac = arg_count(av);
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		if (i + 1 < ac)
			ft_putchar(' ');
		i += 1;
	}
	ft_putchar('\n');
	return (0);
}
