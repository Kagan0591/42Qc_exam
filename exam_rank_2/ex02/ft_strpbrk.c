#include <stdio.h>
#include <string.h>
// Reproduce the beaviour of strpblk function
char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	j = 0;

	while (*s1)
	{
		while (s2[j])
		{
			if (s1[0] == s2[j])
				return ((char*)s1);
			j++;
		}
		j = 0;
		s1++;
	}
	return (NULL);
}


int	main(int argc, char **argv)
{
	(void) argc;
	printf("From original cmd:: %s\n", strpbrk(argv[1], argv[2]));
	printf("From my cmd:: %s\n", ft_strpbrk(argv[1], argv[2]));
	return (0);
}

