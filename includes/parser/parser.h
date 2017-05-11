/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:58:54 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/10 17:18:05 by oyagci           ###   ########.fr       */
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
	t_scommand	*s_command;
	t_cmd_name	*cmd_name;
	t_filename	*filename;
	t_io_file	*io_file;
};

typedef struct				s_ptree
{
	union u_node	content;
	enum e_ntype	type;
}							t_ptree;

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

t_ptree			*ptree_new(enum e_ntype type);

#endif
