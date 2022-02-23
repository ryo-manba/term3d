#include "input.h"
#include <termios.h>
#include <fcntl.h>
#include "tm_utils.h"

#define EOT 4

static int	xtcsetattr(
		int fildes, int optional_actions, const struct termios *termios_p)
{
	if (tcsetattr(fildes, optional_actions, termios_p) == -1)
		print_error_exit(NULL);
	return (0);
}

static int	xtcgetattr(int fildes, struct termios *termios_p)
{
	if (tcgetattr(fildes, termios_p) == -1)
		print_error_exit(NULL);
	return (0);
}

static bool	is_eot(int input_char)
{
	if (input_char == EOT)
		return (true);
	else
		return (false);
}

static void	set_non_blocking_stdin(struct termios *setting)
{
	xtcgetattr(STDIN_FILENO, setting);
	setting->c_lflag &= ~(ECHO | ICANON);
	xtcsetattr(STDIN_FILENO, TCSANOW, setting);
	if (fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK) == -1)
		print_error_exit(NULL);
}

bool	input_setkey(int *key)
{
	struct termios	setting;
	int				input_char;

	set_non_blocking_stdin(&setting);
	input_char = getchar();
	xtcsetattr(STDIN_FILENO, TCSANOW, &setting);
	if (fcntl(STDIN_FILENO, F_SETFL, setting) == 1)
		print_error_exit(NULL);
	*key = input_char;
	return (is_eot(input_char));
}
