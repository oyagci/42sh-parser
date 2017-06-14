/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:58:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/29 13:46:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/ptree_free.h>
#include <parser/parser.h>
#include <stdlib.h>

void			ptree_free(t_ptree **tree)
{
	if ((*tree) && *tree != (void *)ERR_SYNTAX)
	{
		if ((*tree)->del)
			(*tree)->del((*tree)->content);
		free((*tree)->content);
		free(*tree);
		*tree = NULL;
	}
}
