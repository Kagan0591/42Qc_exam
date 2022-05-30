#include <unistd.h>
#include <stdlib.h>

int     ft_strlen_no_doubly_space(char * str)
{
        int     i = 0;
        int     j = 0;

        while (str[i])
        {       
                i++;
                j++;
                while (str[i] && str[i + 1] == ' ')
                        i++;
        }
        return(j);
}

char *rem_space_on_str(char *str)
{
	int	i = 0;
	int	j = 0;
	char *new_str = malloc(sizeof(char *) * ft_strlen_no_doubly_space(str)); 

	while (str[i])
	{
		new_str[j] = str[i];
		if (str[i] == ' ')
		{
			while (str[i + 1] == ' ')
				i++;
		}
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

void	ft_putstr(char *str)
{
	int	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*treated_str;

	if (argc != 2)
		return (1);
	treated_str = rem_space_on_str(argv[1]);
	ft_putstr(treated_str);
	return (0);
}

