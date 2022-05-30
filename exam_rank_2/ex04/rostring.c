#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int	ft_strlen_no_doubly(char *str, char c)
{
	int	i = 0;
	int	count = 0;

	while (str[i])
	{
		if (str[i] == c)
		{		
			while (str[i + 1] && str[i + 1] == c)
				i++;
		}
		count++;
		i++;
	}
	return (count);
}


char *epur_str(char *str)
{
	char	*new_str;
	int	i = 0;
	int	j = 0;

	new_str = malloc(sizeof(char *) * ft_strlen_no_doubly(str, 32));

	while (str[i])
	{
		
		if (str[i] == 32)
		{
			while (str[i + 1] && str[i + 1] == 32)
				i++;
		}
		new_str[j] = str[i];
		i++;
		j++;

	}
	return (new_str);
}

char	*str_alter__move_word(char *str)
{
	int	i = 0;
	int	j = 0;
	int	word_len = 0;
	char	*new_str;
	char	*word_tmp;

	new_str = malloc(sizeof(char *) * ft_strlen_no_doubly(str, 32));
	while (str[word_len])
	{
		if (str[word_len] != 32)
		{
			while (str[word_len] && str[word_len] != 32)
			{
				word_len++;
			}
			break;
		}
		word_len++;
	}
	word_tmp = malloc(sizeof(char *) * word_len);
	word_len -= 1;
	while (str[i])
	{
		while (str[i] == 32)
			i++;
		while (i <= word_len)
		{
			word_tmp[j] = str[i];
			i++;
			j++;
		}
 		while (str[i] == 32)
			i++;
		j = 0;
		while (str[i])
		{
			new_str[j] = str[i];
			i++;
			j++;
		}
		new_str[j] = 32;
		j++;
		i = 0;
		while (word_tmp[i])
		{
			new_str[j] = word_tmp[i];
			i++;
			j++;
		}		
	}
	return (new_str);
}

// TESTER LA FONCTION STR_ALTER_MOVE_WORD
int	main(int argc, char **argv)
{
	//int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	printf("EPUR RESULT :: %s\n", epur_str(argv[1]));
	printf("ALTER STR RESULT :: %s\n", str_alter__move_word(argv[1]));
	return (0);
}
