/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:24:11 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 17:00:42 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			simple_command_free(t_spcommand *sp)
{
	ptree_free(&sp->prefix);
	ptree_free(&sp->suffix);
	ptree_free(&sp->name);
	ptree_free(&sp->word);
}
