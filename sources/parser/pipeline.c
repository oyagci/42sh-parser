/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:53:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 16:17:53 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void		free_pipeline(t_pipeline **pline)
{
	free_pipe_sequence(&(*pline)->pseq);
	free(*pline);
	*pline = NULL;
}

t_pipeline	*pipeline(t_parser *p)
{
	t_pipeline		*pline;
	t_pipe_sequence	*pseq;

	pseq = NULL;
	if ((pline = ft_memalloc(sizeof(t_pipeline))))
	{
		if ((pseq = pipe_sequence(p)))
		{
			if (pseq == (void *)ERR_SYNTAX)
			{
				free_pipeline(&pline);
				return ((void *)ERR_SYNTAX);
			}
			pline->pseq = pseq;
		}
		else
			free_pipeline(&pline);
	}
	return (pline);
}
