/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:58:54 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 13:17:23 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <lexer/lexer.h>
# include <libft.h>

typedef struct s_root				t_root;
typedef struct s_cmd_name			t_cmd_name;
typedef struct s_io_redirect		t_io_redirect;
typedef struct s_io_file			t_io_file;
typedef struct s_filename			t_filename;

typedef struct s_parser				t_parser;
typedef struct s_ptree				t_ptree;
typedef struct s_complete_command	t_complete_command;
typedef struct s_nlist				t_nlist;
typedef struct s_and_or				t_and_or;
typedef struct s_pipeline			t_pipeline;
typedef struct s_spcommand			t_spcommand;

struct						s_parser
{
	t_list		*tlst;
	t_ptree		*ptree;
};

enum						e_io_type
{
	IT_NONE,
	IT_LESS,
	IT_GREAT,
	IT_GREATAND,
	IT_LESSAND
};

enum						e_ntype
{
	NT_ROOT,
	NT_COMPLETE_COMMAND,
	NT_LIST,
	NT_AND_OR,
	NT_SIMPLE_COMMAND,
	NT_CMD_NAME,
	NT_IO_REDIRECT,
	NT_IO_FILE,
	NT_FILENAME,
};

union						u_node
{
	t_root				*root;
	t_complete_command	*cpcmd;
	t_nlist				*list;
	t_and_or			*and_or;
	t_pipeline			*pipeline;

	t_spcommand			*sp_command; t_cmd_name			*cmd_name;
	t_filename			*filename;
	t_io_file			*io_file;
	t_io_redirect		*io_redirect;
};

struct						s_ptree
{
	enum e_ntype	type;
	union u_node	content;
};

struct						s_root
{
	t_list	*nodes;
};

struct						s_spcommand
{
	t_list	*prefix;
	t_list	*suffix;
	t_list	*io;
	t_list	*av;
};

struct						s_cmd_name
{
	char	*data;
};

struct						s_filename
{
	char	*data;
};

struct						s_io_redirect
{
	int			io_number;
	t_ptree		*io_file;
	t_ptree		*io_here;
};

struct						s_io_file
{
	enum e_io_type	type;
	t_ptree			*filename;
};

struct						s_complete_command
{
	t_ptree	*list;
};

struct						s_nlist
{
	t_ptree	*list;
	t_ptree	*and_or;
};

/*
** and_or
** content should be put in another file and_or.h
*/

enum						e_and_or
{
	AO_UNDEFINED,
	AO_FIRST,
	AO_OR,
	AO_AND
};

struct						s_ao_branch
{
	enum e_and_or	type;
	t_ptree			*pipeline;
}

struct						s_and_or
{
	t_list			*branches;
};

/*
** and_or END
*/

t_ptree			*ptree_init(void);
t_ptree			*ptree_new(enum e_ntype type);

int				parser_expect(t_parser *p, enum e_token type);

t_ptree			*complete_command(t_parser *p);
t_ptree			*list(t_parser *p);
t_ptree			*and_or(t_parser *p);
t_ptree			*pipeline(t_parser *p);

t_ptree			*cmd_name(t_parser *p);
t_ptree			*filename(t_parser *p);
t_ptree			*io_file(t_parser *p);
t_ptree			*io_here(t_parser *p);

void			del_node(t_ptree *node);
void			del_root(t_root *root);
void			del_filename(t_filename *fname);
void			del_io_file(t_io_file*iofile);
void			del_io_redirect(t_io_redirect *node);
void			complete_command_del(t_complete_command *cpcmd);

#endif
