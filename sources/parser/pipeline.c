/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:53:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 14:00:29 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_ptree			*pipeline_new()
{
	t_ptree	*node;

	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_PIPELINE;
		if ((node->content = ft_memalloc(sizeof(union u_node))))
		{
			del_node(node);
			return (NULL);
		}
	}
}

t_ptree			*pipeline(t_parser *p)
{
	(void)p;
	return (NULL);
}
