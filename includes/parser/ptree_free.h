/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_free.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:42:22 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 13:08:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTREE_FREE_H
# define PTREE_FREE_H

# include <parser/parser.h>

typedef struct	s_free_tuple
{
	enum e_ntype	type;
	void			(*f);
}				t_free_tuple;

#endif
