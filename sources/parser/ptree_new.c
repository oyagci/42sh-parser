/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:28:08 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 14:24:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <parser/ptree_free.h>
#include <libft.h>
#include <stdlib.h>

void			(*get_freeing_func(enum e_ntype type))(union u_node *)
{
	t_free_tuple const	tuple[] = {
		{ NT_SIMPLE_COMMAND, simple_command_free },
		{ NT_CMD_NAME, cmd_name_free }, { NT_CMD_WORD, cmd_word_free },
		{ NT_IO_HERE, io_here_free }, { NT_HERE_END, here_end_free },
		{ NT_FILENAME, filename_free }, { NT_IO_FILE, io_file_free },
		{ NT_IO_REDIRECT, io_redirect_free },
		{ NT_REDIRECT_LIST, redirect_list_free },
		{ NT_CMD_PREFIX, cmd_prefix_free },
		{ NT_CMD_SUFFIX, cmd_suffix_free },
		{ NT_AND_OR, and_or_free },
		{ NT_LIST, list_free },
		{ NT_COMPLETE_COMMAND, complete_command_free },
		{ NT_PIPELINE, pipeline_free },
		{ NT_PIPE_SEQUENCE, pipe_sequence_free },
		{ NT_COMMAND, command_free },
		{ NT_COMPOUND_COMMAND, compound_command_free },
		{ NT_SUBSHELL, subshell_free },
		{ NT_COMPOUND_LIST, compound_list_free },
		{ NT_TERM, term_free }
	};
	size_t const		sz = sizeof(tuple) / sizeof(t_free_tuple);
	size_t				i;

	i = 0;
	while (i < sz)
	{
		if (type == tuple[i].type)
			return (tuple[i].f);
		i += 1;
	}
	return (NULL);
}

t_ptree			*ptree_new(enum e_ntype type)
{
	t_ptree	*node;

	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = type;
		if (!(node->content = ft_memalloc(sizeof(union u_node))))
		{
			free(node);
			return (NULL);
		}
		node->del = get_freeing_func(type);
	}
	return (node);
}
