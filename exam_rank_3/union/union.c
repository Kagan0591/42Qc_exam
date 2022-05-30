#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void	ft_putstr(char *str)
{
	while (str)
	{
		write(1, &str, 1);
		str++;
	}
}
static int	ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static char	*concat_strings(char *str_1, char *str_2)
{
	char	*final_str;
	int		i;
	int		j;

	final_str = malloc(sizeof(char) * (ft_strlen(str_1) + ft_strlen(str_2) + 1));
	if (!final_str)
		return (0);
	i = 0;
	j = 0;
	while (str_1[i] != '\0')
	{
		final_str[j] = str_1[i];
		i++;
		j++;
	}
	i = 0;
	while (str_2[i] != '\0')
	{
		final_str[j] = str_2[i];
		i++;
		j++;
	}
	final_str[j] = '\0';
	return (final_str);
}

int	main(int argc, char **argv)
{
	(void) argc;
	char	*concat_string;
	char	*char_retained;
	int		i;
	int		j;

	concat_string = concat_strings(argv[1], argv[2]);
	char_retained = calloc(sizeof(char), ft_strlen(concat_string));
	i = 0;
	j = 0;
	while (concat_string[i] != '\0')
	{
		if (j == i)
		{
			char_retained[j] = concat_string[i]; // pour copier le premier char, si rien \0
			i++;
		}
		while (char_retained[j])
		{
			if (concat_string[i] == char_retained[j])
				while (char_retained[j] != '\0')
					{
						char_retained[j] = concat_string[i];
						j++;
 					}

			j++;
		}
		if (concat_string[i] != char_retained[j])
		{
			while (char_retained[j] != '\0')

			char_retained[j] = concat_string[i];
		}
		i++;
		j = 0;
	}
	ft_putstr(char_retained);
	return(0);
}
