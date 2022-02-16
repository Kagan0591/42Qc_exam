#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

bool	ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == c)
			return (true);
	}
	return (false);
}

void	add_first_appeared_char(char **final_list_of_char, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr((*final_list_of_char), str[i]) == false)
		{
			(*final_list_of_char)[j] = str[i];
			j++;
		}
	i++;
	}
}

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*ret_str;

	i = 0;
	ret_str = malloc(sizeof(char) * (ft_strlen(argv[1]) + ft_strlen(argv[2])));
	if (argc != 3)
		return (write(1, "\n", 1));
	add_first_appeared_char(&ret_str, argv[1]);
	ft_putstr(ret_str);
	while (ret_str[i] != '\0')
		i++;
	add_first_appeared_char(&ret_str, argv[2]);
	ft_putstr(ret_str);
	free (ret_str);
	return (0);



	// while (argv[1] != '\0')
	// {
	// 	if (ft_strchr(ret_str, argv[1][i]) == false)
	// 	{
	// 		ret_str[k] = argv[1][i];
	// 		k++;
	// 	}
	// }
	return (0);
}