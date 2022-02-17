#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

int		ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	str[256];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_strchr(str[j], argv[1][i]) == 1)
			i++;
		str[j] = argv[1][i];
		j++;
		i++;
	}
	ft_putstr(
	return (0);
}	

