#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char		ft_strchr(char *str, char c)
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
	(void) argc;
	char	keeped_chars[256];
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if (argc != 3)
		return (write(1, "\n", 1));
	while (argv[1][i] != '\0')
	{
		if (ft_strchr(argv[2], argv[1][i]) == 1)
			if (ft_strchr(keeped_chars, argv[1][i]) == 0)
			{
				keeped_chars[j] = argv[1][i];
				j++;
			}
		i++;
	}
	ft_putstr(keeped_chars);
	return (0);
}
