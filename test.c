#include <libft.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <termcap.h>

int			main(void)
{
	struct termios	attr;
	char			*buf = ft_strnew(0);
	unsigned char		c = 0;

	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~(ICANON | ECHO);
	attr.c_cc[VMIN] = 1;
	attr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);

	while (1)
	{
		read(0, &c, 1);
		if (!(c & 128))
		{
			ft_putchar(c);
			buf = ft_strcjoin(buf, c);
		}
		if (c == '\n')
		{
			ft_putendl("Result:");
			write(1, buf, strlen(buf));
			ft_strclr(buf);
		}
	}
	return (0);
}
