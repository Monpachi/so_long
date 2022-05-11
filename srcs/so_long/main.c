#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	int	width_max;

	width_max = check_width(argv);
	(void)argc;
	graphic(argv, width_max);
}
