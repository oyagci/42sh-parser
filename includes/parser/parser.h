/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:58:54 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 15:00:31 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <lexer/lexer.h>
# include <libft.h>

# define ERR_SYNTAX	0x0000DEAD

typedef struct s_parser				t_parser;
typedef struct s_root				t_root;
typedef struct s_cmd_prefix			t_cmd_prefix;
typedef struct s_cmd_name			t_cmd_name;
typedef struct s_cmd_word			t_cmd_word;
typedef struct s_cmd_suffix			t_cmd_suffix;
typedef struct s_redirect_list		t_redirect_list;
typedef struct s_io_redirect		t_io_redirect;
typedef struct s_io_file			t_io_file;
typedef struct s_io_here			t_io_here;
typedef struct s_here_end			t_here_end;
typedef struct s_filename			t_filename;
typedef struct s_separator_op		t_separator_op;
typedef struct s_command			t_command;
typedef struct s_complete_command	t_complete_command;
typedef struct s_nlist				t_nlist;
typedef struct s_and_or				t_and_or;
typedef struct s_ao_branch			t_ao_branch;
typedef struct s_pipeline			t_pipeline;
typedef struct s_simple_command		t_simple_command;
typedef struct s_pipe_sequence		t_pipe_sequence;
typedef struct s_compound_command	t_compound_command;
typedef struct s_subshell			t_subshell;
typedef struct s_term				t_term;
typedef struct s_compound_list		t_compound_list;
typedef struct s_separator			t_separator;
typedef struct s_linebreak			t_linebreak;
typedef struct s_newline_list		t_newline_list;

struct								s_separator
{
	t_separator_op	*sepop;
};

struct								s_parser
{
	t_list				*tlst;
	t_complete_command	*cplcmd;
};

enum								e_ntype
{
	NT_ROOT,
	NT_COMPLETE_COMMAND,
	NT_LIST,
	NT_AND_OR,
	NT_SIMPLE_COMMAND,
	NT_CMD_NAME,
	NT_IO_REDIRECT,
	NT_IO_FILE,
	NT_IO_HERE,
	NT_FILENAME,
	NT_PIPELINE,
	NT_HERE_END,
	NT_REDIRECT_LIST,
	NT_SEPARATOR_OP,
	NT_CMD_PREFIX,
	NT_CMD_SUFFIX,
	NT_CMD_WORD,
	NT_LINEBREAK,
	NT_NEWLINE_LIST,
	NT_PIPE_SEQUENCE,
	NT_COMMAND,
	NT_COMPOUND_COMMAND,
	NT_SUBSHELL,
	NT_TERM,
	NT_COMPOUND_LIST,
	NT_SEPARATOR,
};

struct								s_term
{
	t_list	*andlst;
};

struct								s_root
{
	t_list	*nodes;
};

struct								s_pipe_sequence
{
	size_t	nb;
	t_list	*commands;
};

struct								s_simple_command
{
	t_cmd_prefix	*prefix;
	t_cmd_suffix	*suffix;
	t_cmd_name		*name;
	t_cmd_word		*word;
};

struct								s_cmd_prefix
{
	t_list	*redirections;
	t_list	*assignements;
};

struct								s_cmd_name
{
	char	*data;
};

struct								s_cmd_word
{
	char	*data;
};

struct								s_cmd_suffix
{
	t_list	*redirections;
	t_list	*words;
};

struct								s_filename
{
	char	*data;
};

struct								s_io_redirect
{
	int			is_default;
	int			io_number;
	t_io_file	*io_file;
	t_io_here	*io_here;
};

enum								e_io_type
{
	IT_NONE,
	IT_LESS,
	IT_GREAT,
	IT_GREATAND,
	IT_LESSAND,
	IT_DGREAT
};

struct								s_io_file
{
	enum e_io_type	type;
	t_filename		*filename;
};

struct								s_complete_command
{
	t_nlist			*list;
	t_separator_op	*sepop;
};

struct								s_nlist
{
	t_list	*andlst;
};

struct								s_and_or
{
	t_list	*pipelines;
};

enum								e_pipeline
{
	PL_DEFAULT,
	PL_AND_IF,
	PL_OR_IF
};

struct								s_pipeline
{
	enum e_pipeline	type;
	t_pipe_sequence	*pseq;
};

struct								s_io_here
{
	t_here_end	*here_end;
};

struct								s_here_end
{
	char	*data;
};

struct								s_redirect_list
{
	t_list	*list;
};

enum								e_separator
{
	SP_AND,
	SP_SEMICOL
};

struct								s_separator_op
{
	enum e_separator	op;
};

enum								e_command_type
{
	CT_COMPOUND_COMMAND,
	CT_SIMPLE_COMMAND
};

struct								s_command
{
	enum e_command_type	type;
	t_simple_command	*scmd;
	t_redirect_list		*rlist;
	t_compound_command	*cpndcmd;
};

struct								s_compound_command
{
	t_subshell	*subshell;
};

struct								s_compound_list
{
	t_term		*term;
};

struct								s_subshell
{
	t_compound_list	*compound_list;
};

struct								s_linebreak
{
};

int									parser_expect(t_parser *p,
		enum e_token type);
int									parser_peek(t_parser *p,
		enum e_token type);

t_and_or							*and_or(t_parser *p);
t_cmd_name							*cmd_name(t_parser *p);
t_cmd_word							*cmd_word(t_parser *p);
t_cmd_prefix						*cmd_prefix(t_parser *p);
t_cmd_suffix						*cmd_suffix(t_parser *p);
t_command							*command(t_parser *p);
t_complete_command					*complete_command(t_parser *p);
t_compound_command					*compound_command(t_parser *p);
t_compound_list						*compound_list(t_parser *p);
t_filename							*filename(t_parser *p);
t_here_end							*here_end(t_parser *p);
t_io_file							*io_file(t_parser *p);
t_io_here							*io_here(t_parser *p);
t_io_redirect						*io_redirect(t_parser *p);
t_linebreak							*linebreak(t_parser *p);
t_nlist								*list(t_parser *p);
t_newline_list						*newline_list(t_parser *p);
t_pipe_sequence						*pipe_sequence(t_parser *p);
t_pipeline							*pipeline(t_parser *p);
t_redirect_list						*redirect_list(t_parser *p);
t_separator							*separator(t_parser *p);
t_separator_op						*separator_op(t_parser *p);
t_simple_command					*simple_command(t_parser *p);
t_subshell							*subshell(t_parser *p);
t_term								*term(t_parser *p);

void								free_and_or(t_and_or **and_or);
void								free_command(t_command **cmd);
void								free_complete_command(t_complete_command **cplcmd);
void								free_io_redirect(t_io_redirect **ioredir);
void								free_prefix(t_cmd_prefix **prefix);
void								free_term(t_term **t);

/*
** cmd_suffix.c
*/
int									add_redirection(t_parser *p, t_cmd_suffix *suffix);

void								print_complete_command(t_complete_command *cplcmd, int indent);
void								print_list(t_nlist *lst, int indent);
void								print_command(t_command *cmd, int indent);
void								print_simple_command(t_simple_command *scmd, int indent);

#endif
