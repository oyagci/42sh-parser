#include <lexer/lexer.h>
#include <parser/parser.h>

void	putindent(int n)
{
	for (int i = 0; i < n; i++)
		ft_putchar(' ');
} 
void	putendl_indent(char *s, int indent)
{
	putindent(indent);
	ft_putendl(s);
}

void	putstr_indent(char *s, int indent)
{
	putindent(indent);
	ft_putstr(s);
}

void	print_filename(t_ptree *node, int indent)
{
	t_filename	*f;

	f = &node->content->filename;
	putendl_indent("[filename]", indent);
	putendl_indent(f->data, indent + 2);
}

void	print_io_type(enum e_io_type type, int indent)
{
	if (type == IT_LESS)
		putendl_indent("IT_LESS", indent);
	else if (type == IT_GREAT)
		putendl_indent("IT_GREAT", indent);
	else if (type == IT_DGREAT)
		putendl_indent("IT_DGREAT", indent);
	else if (type == IT_GREATAND)
		putendl_indent("IT_GREATAND", indent);
	else if (type == IT_LESSAND)
		putendl_indent("IT_LESSAND", indent);
}

void	print_io_file(t_ptree *node, int indent)
{
	t_io_file	*file;

	file = &node->content->io_file;
	putendl_indent("[io_file]", indent);
	print_io_type(file->type, indent + 2);
	print_filename(file->filename, indent + 2);
}

void	print_here_end(t_ptree *node, int indent)
{
	putendl_indent("[here_end]", indent);
	putendl_indent(node->content->here_end.data, indent + 2);
}

void	print_io_here(t_ptree *node, int indent)
{
	t_io_here	*file;

	file = &node->content->io_here;
	putendl_indent("[io_here]", indent);
	print_here_end(file->here_end, indent + 2);
}

void	print_io_redirect(t_ptree *node, int indent)
{
	t_io_redirect *redirect;

	if (node->type != NT_IO_REDIRECT)
		return ;

	redirect = &node->content->io_redirect;

	putendl_indent("[io_redirect]", indent);
	putstr_indent("is_default: ", indent + 2);
	ft_putnbr(redirect->is_default);
	ft_putchar('\n');

	putstr_indent("io_number: ", indent + 2);
	ft_putnbr(redirect->io_number);
	ft_putchar('\n');

	redirect->io_file ? print_io_file(redirect->io_file, indent + 2) : 0;
	redirect->io_here ? print_io_here(redirect->io_here, indent + 2) : 0;
}

void	print_prefix(t_ptree *node, int indent)
{
	t_cmd_prefix	*prefix;
	t_list			*head;

	if (!node)
		return ;
	if (node->type != NT_CMD_PREFIX)
	{
		putendl_indent("!NT_CMD_PREFIX", indent);
		return ;
	}

	putendl_indent("[cmd_prefix]", indent);
	indent += 2;
	prefix = &node->content->cmd_prefix;
	head = prefix->redirections;
	while (prefix->redirections)
	{
		print_io_redirect(((t_ptree *)prefix->redirections->content), indent);
		prefix->redirections = prefix->redirections->next;
	}
	prefix->redirections = head;
	head = prefix->assignements;
	while (prefix->assignements)
	{	
		putendl_indent((char *)prefix->assignements->content, indent);
		prefix->assignements = prefix->assignements->next;
	}
	prefix->assignements = head;
}

void	print_suffix(t_ptree *node, int indent)
{
	t_cmd_suffix	*suffix;
	t_list			*head;

	if (!node)
		return ;
	if (node->type != NT_CMD_SUFFIX)
	{
		putendl_indent("!NT_CMD_SUFFIX", indent);
		return ;
	}
	putendl_indent("[cmd_suffix]", indent);

	suffix = &node->content->cmd_suffix;
	head = suffix->words;
	while (suffix->words)
	{
		putendl_indent(suffix->words->content, indent + 2);
		suffix->words = suffix->words->next;
	}
	suffix->words = head;
	indent += 2;
	head = suffix->redirections;
	while (suffix->redirections)
	{
		print_io_redirect(suffix->redirections->content, indent);
		suffix->redirections = suffix->redirections->next;
	}
	suffix->redirections = head;
}

void	print_cmd_name(t_ptree *node, int indent)
{
	t_cmd_name	*name;

	if (!node)
		return ;
	if (node->type != NT_CMD_NAME)
	{
		putendl_indent("!NT_CMD_NAME", indent);
		return ;
	}

	putendl_indent("[cmd_name]", indent);

	name = &node->content->cmd_name;
	putendl_indent(name->data, indent + 2);
}

void	print_cmd_word(t_ptree *node, int indent)
{
	t_cmd_word	*word;

	if (!node)
		return ;
	putendl_indent("[cmd_word]", indent);
	word = &node->content->cmd_word;
	putendl_indent(word->data, indent + 2);
}

void	print_simple_command(t_ptree *node, int indent)
{
	t_spcommand	*spcmd;

	if (!node || node == (void *)ERR_SYNTAX)
		return ;
	if (node->type != NT_SIMPLE_COMMAND)
	{
		putendl_indent("!NT_SIMPLE_COMMAND", indent);
		return ;
	}

	putendl_indent("[simple_command]", indent);

	indent += 2;
	spcmd = &node->content->sp_command;
	print_prefix(spcmd->prefix, indent);
	print_cmd_name(spcmd->name, indent);
	print_cmd_word(spcmd->word, indent);
	print_suffix(spcmd->suffix, indent);
}

void	print_pipe_sequence(t_ptree *node, int indent)
{
	t_list	*head;

	if (!node || node == (void *)ERR_SYNTAX)
		return ;

	putendl_indent("[pipe_sequence]", indent);
	head = node->content->pipe_sequence.commands;
	while (head)
	{
		print_command(head->content, indent + 2);
		head = head->next;
	}
}

void	print_pipeline(t_ptree *node, int indent)
{
	if (!node || node == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[pipeline]", indent);
	print_pipe_sequence(node->content->pipeline.pipe_sequence, indent + 2);
}

void	print_and_or(t_ptree *node, int indent)
{
	t_list	*head;
	if (!node || node == (void *)ERR_SYNTAX)
		return ;

	head = node->content->and_or.pipelines;
	putendl_indent("[and_or]", indent);
	while (node->content->and_or.pipelines)
	{
		print_pipeline(node->content->and_or.pipelines->content, indent + 2);
		node->content->and_or.pipelines = node->content->and_or.pipelines->next;
	}
	node->content->and_or.pipelines = head;
}

void	print_term(t_ptree *node, int indent)
{
	t_list	*head;

	if (!node || node == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[term]", indent);
	head = node->content->term.andlst;
	while (node->content->term.andlst)
	{
		print_and_or(node->content->term.andlst->content, indent + 2);
		node->content->term.andlst = node->content->term.andlst->next;
	}
	node->content->term.andlst = head;
}

void	print_compound_list(t_compound_list *cl, int indent)
{
	if (!cl || cl == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[compound_list]", indent);
	print_term(cl->term, indent + 2);
}

void	print_subshell(t_ptree *node, int indent)
{
	if (!node || node == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[subshell]", indent);
	print_compound_list(node->content->subshell.compound_list, indent + 2);
}

void	print_compound_command(t_ptree *node, int indent)
{
	if (!node || node == (void *)ERR_SYNTAX)
		return ;

	putendl_indent("[compound_command]", indent);
	print_subshell(node->content->compound_command.subshell, indent + 2);
}

void	print_redirect_list(t_ptree *node, int indent)
{
	t_list	*head;

	if (!node)
		return ;

	head = node->content->redirect_list.list;
	while (head)
	{
		print_io_redirect(head->content, indent);
		head = head->next;
	}
}

void	print_command(t_ptree *node, int indent)
{
	t_command *cmd;

	if (!node || node == (void *)ERR_SYNTAX)
	{
		putendl_indent("NULL!", indent);
		return ;
	}

	cmd = &node->content->command;

	putendl_indent("[command]", indent);
	if (cmd->cmd->type == NT_SIMPLE_COMMAND)
		print_simple_command(cmd->cmd, indent + 2);
	else if (cmd->cmd->type == NT_COMPOUND_COMMAND)
	{
		print_compound_command(cmd->cmd, indent + 2);
		print_redirect_list(cmd->redirect, indent + 2);
	}
}

void	print_list(t_ptree *node, int indent)
{
	t_list	*head;

	if (!node || node == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[list]", indent);
	head = node->content->list.andlst;
	while (head)
	{
		print_and_or(head->content, indent + 2);
		head = head->next;
	}
}

void	print_separator_op(t_ptree *node, int indent)
{
	t_separator_op	*sp;

	if (!node)
		return ;
	sp = &node->content->separator_op;
	putendl_indent("[separator_op]", indent);
	if (sp->op == SP_AND)
		putendl_indent("AND", indent + 2);
	else if (sp->op == SP_SEMICOL)
		putendl_indent("SEMICOL", indent + 2);
}

void	print_separator(t_ptree *node, int indent)
{
	if (!node || node == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[separator]", indent);
	print_separator_op(node->content->separator.separator_op, indent + 2);
}

void	print_complete_command(t_ptree *node, int indent)
{
	t_ptree	*head;

	if (!node || node == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[complete_command]", indent);
	head = node->content->cpcmd.list;
	print_list(head, indent + 2);
	print_separator_op(node->content->cpcmd.separator_op, indent + 2);
}
