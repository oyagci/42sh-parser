/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:58:54 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 14:04:12 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>

typedef struct s_scommand	t_scommand;
typedef struct s_cmd_name	t_cmd_name;
typedef struct s_filename	t_filename;
typedef struct s_io_file	t_io_file;
typedef struct s_parser		t_parser;
typedef struct s_ptree		t_ptree;
typedef struct s_root		t_root;

struct						s_parser
{
	t_list		*tlst;
	t_ptree		*ptree;
};

enum						e_io_type
{
	IT_LESS,
	IT_GREAT,
	IT_GREATAND,
	IT_LESSAND
};

enum						e_ntype
{
	NT_ROOT,
	NT_SIMPLE_COMMAND,
	NT_CMD_NAME,
	NT_FILENAME,
	NT_IO_FILE
};

union						u_node
{
	t_root		*root;
	t_scommand	*s_command;
	t_cmd_name	*cmd_name;
	t_filename	*filename;
	t_io_file	*io_file;
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

typedef struct				s_scommand
{
	t_list	*io;
	t_list	*av;
}							t_scommand;

struct						s_cmd_name
{
	char	*data;
};

struct						s_filename
{
	char	*data;
};

struct						s_io_file
{
	enum e_io_type	type;
	t_ptree			*filename;
};

t_ptree			*ptree_init(void);
t_ptree			*ptree_new(enum e_ntype type);

t_ptree			*cmd_name(t_parser *p);

#endif
