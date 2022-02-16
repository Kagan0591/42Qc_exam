#include <unistd.h>
#include <stdbool.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 2);
}

bool	isequal_char(char a, char b)
{
	if (a == b)
		return (true);
	return (false);
}

bool	isrepeated_char(char *str, int position)
{
	int		i;

	i = 0;
	while (i != position)
	{
		if (isequal_char(str[i], str[position]) == true)
			return (true);
		i++;
	}
	return (false);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc != 3)
		return (write(1, "\n", 1));
	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (isrepeated_char(argv[1], i) == false)
		{
			while (argv[2][j] != '\0')
			{
				if (isrepeated_char(argv[2], j) == false)
				{
					if (isequal_char(argv[1][i], argv[2][j]) == true)
						write(1, &argv[2][j], 1);
				}
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (write(1, "\n", 1));
}
