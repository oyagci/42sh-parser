/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delimite_current_token.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:58:28 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 12:31:02 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

enum e_token	get_token_type(t_token *t)
{
	char *const			ops[] = { "<<", "<&", ">>", ">&", "||", "&&", "<", ">",
		";", "|", "\n", "(", ")" };
	const enum e_token	types[] = { T_DLESS, T_LESSAND, T_DGREAT, T_GREATAND,
		T_OR_IF, T_AND_IF, T_LESS, T_GREAT, T_SEMICOL, T_PIPE, T_NEWLINE,
		T_LBRACKET, T_RBRACKET };
	size_t const		sz = sizeof(ops) / sizeof(char *);
	size_t				i;

	i = 0;
	while (i < sz)
	{
		if (ft_strequ(t->data, ops[i]))
			return ((enum e_token)types[i]);
		i += 1;
	}
	return (0);
}

int				is_io_number(t_token *t, char *input)
{
	size_t	i;

	if (*input && (*input == '>' || *input == '<'))
	{
		i = 0;
		while (t->data[i] != 0)
		{
			if (!ft_isdigit(t->data[i]))
				return (0);
			i += 1;
		}
		return (1);
	}
	return (0);
}

/*
** TODO: Error Handling
*/
void			lexer_add_current(t_lexer *lex)
{
	t_list	*elem;
	t_list	*tmp;

	tmp = lex->tlst;
	elem = ft_lstnew(NULL, 0);
	elem->content = lex->current;
	if (tmp && ((t_token *)tmp->content)->type != T_END)
	{
		while (((t_token *)tmp->next->content)->type != T_END)
			tmp = tmp->next;
		elem->next = tmp->next;
		tmp->next = elem;
	}
	else
	{
		elem->next = lex->tlst;
		lex->tlst = elem;
	}
}

int				lexer_delimite_current_token(t_lexer *lex)
{
	enum e_token	type;

	if (lex->current)
	{
		if (is_io_number(lex->current, lex->input_p))
			lex->current->type = T_IO_NUMBER;
		else
		{
			type = get_token_type(lex->current);
			lex->current->type = (type != 0 ? type : T_WORD);
		}
		lexer_add_current(lex);
		lex->current = 0;
	}
	return (OK);
}
