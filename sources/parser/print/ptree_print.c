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

void	print_filename(t_filename *f, int indent)
{
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

void	print_io_file(t_io_file *file, int indent)
{
	putendl_indent("[io_file]", indent);
	print_io_type(file->type, indent + 2);
	print_filename(file->filename, indent + 2);
}

void	print_here_end(t_here_end *hend, int indent)
{
	putendl_indent("[here_end]", indent);
	putendl_indent(hend->data, indent + 2);
}

void	print_io_here(t_io_here *iohere, int indent)
{
	putendl_indent("[io_here]", indent);
	print_here_end(iohere->here_end, indent + 2);
}

void	print_io_redirect(t_io_redirect *redirect, int indent)
{
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

void	print_prefix(t_cmd_prefix *prefix, int indent)
{
	t_list			*head;

	if (!prefix)
		return ;

	putendl_indent("[cmd_prefix]", indent);
	indent += 2;
	head = prefix->redirections;
	while (prefix->redirections)
	{
		print_io_redirect(prefix->redirections->content, indent);
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

void	print_suffix(t_cmd_suffix *suffix, int indent)
{
	t_list			*head;

	if (!suffix || suffix == (void*)ERR_SYNTAX)
		return ;
	putendl_indent("[cmd_suffix]", indent);
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

void	print_cmd_name(t_cmd_name *cmdname, int indent)
{
	if (!cmdname)
		return ;

	putendl_indent("[cmd_name]", indent);
	putendl_indent(cmdname->data, indent + 2);
}

void	print_cmd_word(t_cmd_word *word, int indent)
{
	if (!word)
		return ;
	putendl_indent("[cmd_word]", indent);
	putendl_indent(word->data, indent + 2);
}

void	print_simple_command(t_simple_command *scmd, int indent)
{
	if (!scmd || scmd == (void *)ERR_SYNTAX)
		return ;

	putendl_indent("[simple_command]", indent);

	indent += 2;
	print_prefix(scmd->prefix, indent);
	print_cmd_name(scmd->name, indent);
	print_cmd_word(scmd->word, indent);
	print_suffix(scmd->suffix, indent);
}

void	print_pipe_sequence(t_pipe_sequence *pseq, int indent)
{
	t_list	*head;

	if (!pseq || pseq == (void *)ERR_SYNTAX)
		return ;

	putendl_indent("[pipe_sequence]", indent);
	head = pseq->commands;
	while (head)
	{
		print_command(head->content, indent + 2);
		head = head->next;
	}
}

void	print_pipeline(t_pipeline *pline, int indent)
{
	if (!pline || pline == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[pipeline]", indent);
	print_pipe_sequence(pline->pseq, indent + 2);
}

void	print_and_or(t_and_or *and_or, int indent)
{
	t_list	*head;
	if (!and_or || and_or == (void *)ERR_SYNTAX)
		return ;

	head = and_or->pipelines;
	putendl_indent("[and_or]", indent);
	while (and_or->pipelines)
	{
		print_pipeline(and_or->pipelines->content, indent + 2);
		and_or->pipelines = and_or->pipelines->next;
	}
	and_or->pipelines = head;
}

void	print_term(t_term *term, int indent)
{
	t_list	*head;

	if (!term || term == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[term]", indent);
	head = term->andlst;
	while (term->andlst)
	{
		print_and_or(term->andlst->content, indent + 2);
		term->andlst = term->andlst->next;
	}
	term->andlst = head;
}

void	print_compound_list(t_compound_list *cl, int indent)
{
	if (!cl || cl == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[compound_list]", indent);
	print_term(cl->term, indent + 2);
}

void	print_subshell(t_subshell *sub, int indent)
{
	if (!sub || sub == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[subshell]", indent);
	print_compound_list(sub->compound_list, indent + 2);
}

void	print_compound_command(t_compound_command *cpndcmd, int indent)
{
	if (!cpndcmd || cpndcmd == (void *)ERR_SYNTAX)
		return ;

	putendl_indent("[compound_command]", indent);
	print_subshell(cpndcmd->subshell, indent + 2);
}

void	print_redirect_list(t_redirect_list *rlist, int indent)
{
	t_list	*head;

	if (!rlist)
		return ;

	head = rlist->list;
	while (head)
	{
		print_io_redirect(head->content, indent);
		head = head->next;
	}
}

void	print_command(t_command *cmd, int indent)
{
	if (!cmd || cmd == (void *)ERR_SYNTAX)
	{
		putendl_indent("NULL!", indent);
		return ;
	}

	putendl_indent("[command]", indent);
	if (cmd->type == CT_SIMPLE_COMMAND)
		print_simple_command(cmd->scmd, indent + 2);
	else if (cmd->type == CT_COMPOUND_COMMAND)
	{
		print_compound_command(cmd->cpndcmd, indent + 2);
		print_redirect_list(cmd->rlist, indent + 2);
	}
	else
		putendl_indent("unknown command", indent);
}

void	print_list(t_nlist *lst, int indent)
{
	t_list	*head;

	if (!lst || lst == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[list]", indent);
	head = lst->andlst;
	while (head)
	{
		print_and_or(head->content, indent + 2);
		head = head->next;
	}
}

void	print_separator_op(t_separator_op *sepop, int indent)
{
	if (!sepop)
		return ;
	putendl_indent("[separator_op]", indent);
	if (sepop->op == SP_AND)
		putendl_indent("AND", indent + 2);
	else if (sepop->op == SP_SEMICOL)
		putendl_indent("SEMICOL", indent + 2);
}

void	print_separator(t_separator *sep, int indent)
{
	if (!sep || sep == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[separator]", indent);
	print_separator_op(sep->sepop, indent + 2);
}

void	print_complete_command(t_complete_command *cplcmd, int indent)
{
	t_nlist	*head;

	if (!cplcmd || cplcmd == (void *)ERR_SYNTAX)
		return ;
	putendl_indent("[complete_command]", indent);
	head = cplcmd->list;
	print_list(head, indent + 2);
	print_separator_op(cplcmd->sepop, indent + 2);
}
