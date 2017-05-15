/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:17:40 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 15:18:32 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			del_filename(t_filename *fname)
{
	free(fname->data);
	free(fname);
}
