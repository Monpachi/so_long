#include "so_long.h"

char	*ber_strcpy(char *dest, char *src)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (src[i] != '.')
	{
		i++;
		if (src[i] == '\0')
			exit_failure("Error, not a valid a map\n");
	}
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j++] = '\0';
	printf("%s\n", dest);
	printf("%d\n", ft_strlen(dest));
	printf("----\n");
	return (dest);
}

int	map_name_check(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
	{
		str = malloc(sizeof(char) * (3 + 1));
		str = ber_strcpy(str, argv[1]);
		if (!ft_strcmp(str, ".ber"))
			return (1);
		else
			exit_failure_free(str, "Error, not a valid a map\n");
	}
	return (0);
}


/* a verifier si je met un (void).ber comme argument, est ce que je le fais?*/
