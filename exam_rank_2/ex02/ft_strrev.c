#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int	len = 0;
	int	i = 0;
	char tmp;

	while (str[len])
		len++;
	len = len - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int	main(void)
{
	char str[] = "Allo";

	ft_strrev(str);
	printf("Result: %s\n", str);
	return (0);
}
