/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:06:30 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 12:16:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

t_lexer			*lexer(char *input)
{
	t_lexer	*lex;
	int		ret;

	if ((lex = lexer_init(input)) == (void *)ERR)
		return ((void *)ERR);
	while (1)
	{
		ret = lexer_get_next_token(lex);
		if (ret == ERR)
		{
			lexer_delete(&lex);
			return ((void *)ERR);
		}
		else if (ret == 1)
			break ;
	}
	return (lex);
}
