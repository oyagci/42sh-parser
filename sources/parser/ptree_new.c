/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:28:08 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/05 17:28:37 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <libft.h>

t_ptree			*ptree_new(enum e_ntype type)
{
	t_ptree	*node;

	if (!(node = ft_memalloc(sizeof(t_ptree))))
		return (NULL);
	node->type = type;
	return (node);
}
