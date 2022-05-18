#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

static int	countnumber(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		count;

	i = 0;
	count = countnumber(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		i++;
	}
	str[count] = '\0';
	while (--count >= i)
	{
		str[count] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

void	move_number(int i)
{
	char	*move;

	move = ft_itoa(i);
	ft_putstr_fd("Move : ", 1);
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
	return ;
}
