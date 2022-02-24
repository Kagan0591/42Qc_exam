#include <unistd.h>

int	ft_strnchr(char *str, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	main(int argc, char **argv)
{
	int	i; // incrementeur de l argument [1]

	i = 0;
	if (argc != 3)
		return (write(1, "\n", 1));
	while (argv[1][i] != '\0')
	{
		/* verifier si le caractere est present en aval dans 
		 * la premiere chaine.
		 * ft_strnchr(char *str, int c, int len);
		 * 0 = non present dans le range donne */
		if (ft_strnchr(argv[1], (int)argv[1][i], i) != 0)
			i++;
		else
			/* verifier si le char est aussi quelque part 
			 * dans l autre argument. Si 0 passer au suivant.
			 * ft_strnchr(char *str, int c, int len )) 
			 * 0 = non present dans le range donne */
			if (ft_strnchr(argv[2], (int)argv[1][i], ft_strlen(argv[2])) == 0)
				i++;
			else
			{
				write(1, &argv[1][i], 1);
				i++;
			}
	}
}
	
