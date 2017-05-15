/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 09:57:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 11:06:03 by oyagci           ###   ########.fr       */
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
	T_WORD,

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

enum					e_symbol
{
	S_END,
	S_QUOTE,
	S_DQUOTE,
	S_BSLASH,
	S_OP,
};

struct					s_lexer
{
	char	*input_p;
	char	quote;
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
int						lexer_init_slst(t_lexer *lex);

int						lexer_get_next_token(t_lexer *lex);

int						lexer_delimite_current_token(t_lexer *lex);

enum e_symbol			lexer_symbol_top(t_lexer *lex);
int						lexer_symbol_push(t_lexer *lex, enum e_symbol sym);
enum e_symbol			lexer_symbol_pop(t_lexer *lex);

int						lexer_current_add_char(t_lexer *lex);
int						lexer_token_new(t_lexer *lex);

void					lexer_delete(t_lexer **lexer);
void					lexer_del_token(void *content, size_t content_size);
void					lexer_del_symbol(void *content, size_t content_size);

int						lexer_check_delimite(t_lexer *lex);
int						lexer_check_quote(t_lexer *lex);
int						lexer_check_top(t_lexer *lex);

int						lexer_expand_current(t_lexer *lex);

int						is_opstart(t_lexer *lex);
int						is_last_opchar(t_lexer *lex);

#endif
