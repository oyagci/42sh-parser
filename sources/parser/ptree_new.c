/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:28:08 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 14:35:49 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <libft.h>
#include <stdlib.h>

t_ptree			*ptree_new(enum e_ntype type)
{
	t_ptree	*node;

	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = type;
		if (!(node->content = ft_memalloc(sizeof(union u_node))))
		{
			free(node);
			return (NULL);
		}
	}
	return (node);
}
