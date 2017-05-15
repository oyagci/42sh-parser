/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_opstart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:52:02 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 10:52:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				is_opstart(t_lexer *lex)
{
	char const		opstarts[] = { '<', '>', '|', '&', ';' };
	size_t const	sz = sizeof(opstarts) / sizeof(char);
	size_t			i;

	i = 0;
	while (i < sz)
	{
		if (*lex->input_p == opstarts[i])
			return (1);
		i += 1;
	}
	return (0);
}
