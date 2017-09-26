/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:53:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/26 16:55:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void		free_pipeline(t_pipeline **pline)
{
	// TODO: free pipe_sequence
	free(*pline);
	*pline = NULL;
}

t_pipeline	*pipeline(t_parser *p)
{
	t_pipeline		*pline;
	t_pipe_sequence	*pseq;

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
