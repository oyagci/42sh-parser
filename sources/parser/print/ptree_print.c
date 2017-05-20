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

void	print_io_redirect(t_ptree *node, int indent)
{
	t_io_redirect *redirect;

	if (node->type != NT_IO_REDIRECT)
		return ;

	redirect = &node->content->io_redirect;

	putendl_indent("[io_redirect]", indent);
	putstr_indent("is_default: ", indent);
	ft_putnbr(redirect->is_default);
	ft_putchar('\n');

	putstr_indent("io_number: ", indent);
	ft_putnbr(redirect->io_number);
	ft_putchar('\n');
}

void	print_prefix(t_ptree *node, int indent)
{
	t_cmd_prefix *prefix;

	if (!node)
		return ;
	if (node->type != NT_CMD_PREFIX)
	{
		putendl_indent("!NT_CMD_PREFIX", indent);
		return ;
	}

	putendl_indent("[cmd_prefix]", indent);
	indent += 4;
	prefix = &node->content->cmd_prefix;
	while (prefix->redirections)
	{
		print_io_redirect(((t_ptree *)prefix->redirections->content), indent);
		prefix->redirections = prefix->redirections->next;
	}
	while (prefix->assignements)
	{	
		putendl_indent((char *)prefix->assignements->content, indent);
		prefix->assignements = prefix->assignements->next;
	}
}

void	print_suffix(t_ptree *node, int indent)
{
	t_cmd_suffix	*suffix;

	if (!node)
		return ;
	if (node->type != NT_CMD_SUFFIX)
	{
		putendl_indent("!NT_CMD_SUFFIX", indent);
		return ;
	}
	putendl_indent("[cmd_suffix]", indent);

	suffix = &node->content->cmd_suffix;
	while (suffix->words)
	{
		putendl_indent(suffix->words->content, indent + 2);
		suffix->words = suffix->words->next;
	}
	indent += 4;
	while (suffix->redirections)
	{
		print_io_redirect(suffix->redirections->content, indent);
		suffix->redirections = suffix->redirections->next;
	}
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

	if (!node)
		return ;
	if (node->type != NT_SIMPLE_COMMAND)
	{
		putendl_indent("!NT_SIMPLE_COMMAND", indent);
		return ;
	}

	putendl_indent("[simple_command]", indent);

	indent += 4;
	spcmd = &node->content->sp_command;
	print_prefix(spcmd->prefix, indent);
	print_cmd_name(spcmd->name, indent);
	print_cmd_word(spcmd->word, indent);
	print_suffix(spcmd->suffix, indent);
}
