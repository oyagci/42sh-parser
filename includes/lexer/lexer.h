/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 09:57:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 11:17:12 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define ERR	-1
# define OK		0

# include <libft.h>

typedef struct s_lexer	t_lexer;
typedef struct s_token	t_token;

enum					e_token
{
	T_TOKEN,

	T_LESS,
	T_LESSAND,
	T_DLESS,
	T_GREAT,
	T_GREATAND,
	T_DGREAT,
	T_PIPE,
	T_OR,
	T_AND,
	T_SEMICOL,
	T_IO_NUMBER,

	T_END,
};

struct					s_lexer
{
	char	*input_p;
	t_list	*tlst;
	t_list	*slst;
	t_token	*current;
};

struct					s_token
{
	enum e_token	type;
	char			*data;
};

t_lexer					*lexer(char *input);
t_lexer					*lexer_init(char *input);
int						lexer_init_tlst(t_lexer *l);
void					lexer_delete(t_lexer **lexer);
int						lexer_get_next_token(t_lexer *lex);
int						lexer_delimite_current_token(t_lexer *lex);

#endif
