/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:02:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 13:54:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <parser.h>
#include <libft.h>

/*
** a	: a T_SEMICOL
**		| T_WORD
*/

t_list			*populate_tlst(void)
{
	t_list	*tlst = NULL;
	t_token tarr[] = {
		{ T_WORD, ft_strdup("ls") },
		{ T_SEMICOL, ft_strdup(";") },
		{ T_WORD, ft_strdup("-la") },
		{ T_SEMICOL, ft_strdup(";") },
		{ T_WORD, ft_strdup("cat") },
		{ T_END, NULL },
	};
	size_t	i = 0;

	while (tarr[i].type != T_END)
	{
		ft_lstpush(&tlst, ft_lstnew(tarr + i, sizeof(t_token)));
		i += 1;
	}
	ft_lstpush(&tlst, ft_lstnew(tarr + i, sizeof(t_token)));
	return (tlst);
}

t_ptree			*a

int				main(void)
{
}
