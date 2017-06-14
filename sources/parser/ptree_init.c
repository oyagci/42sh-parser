/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:14:01 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 14:26:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

t_ptree			*ptree_init(void)
{
	t_ptree	*tree;

	tree = ptree_new(NT_ROOT);
	return (tree);
}
