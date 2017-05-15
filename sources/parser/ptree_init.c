/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:14:01 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 13:20:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

t_ptree			*ptree_init(void)
{
	t_ptree	*tree;

	if ((tree = ft_memalloc(sizeof(t_ptree))))
	{
		tree->type = NT_ROOT;
		if ((tree->content.root = ft_memalloc(sizeof(t_root))) == NULL)
		{
			free(tree);
			return (NULL);
		}
	}
	return (tree);
}
