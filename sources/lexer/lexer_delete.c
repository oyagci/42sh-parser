/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:26:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 12:33:57 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

void			lexer_delete(t_lexer **lexer)
{
	ft_lstdel(&(*lexer)->tlst, lexer_del_token);
	ft_lstdel(&(*lexer)->slst, lexer_del_symbol);
	free(*lexer);
	*lexer = NULL;
}
