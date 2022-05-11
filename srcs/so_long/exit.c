#include "so_long.h"

char	exit_failure(char *s)
{
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

char	exit_failure_free(char *freethis, char *s)
{
	free (freethis);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

char	exit_failure_free2(char *freethis, t_map **freethistoo, char *s)
{
	if (freethis)
		free (freethis);
	if (freethistoo)
		ft_lstclear(freethistoo);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}
