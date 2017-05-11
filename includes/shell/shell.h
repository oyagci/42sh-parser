/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:46:48 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/11 16:58:31 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <lexer/lexer.h>
# include <libft.h>

/*
** ERROR CODES
*/

# define E_NOSUCHFILE	1
# define E_NOACCESS		2

# define FT_NOENT		1
# define FT_ACCESS		2

typedef struct		s_builtin
{
	char	*str;
	int		(*f)(char **);
}					t_builtin;

size_t				arg_count(char **av);
int					dup3(int a, int b);

#endif
