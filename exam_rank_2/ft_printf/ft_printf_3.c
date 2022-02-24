#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

typedef struct	s_print
{
	va_list	(valist);
	int	count;
}s_print;

int	ft_numlen(int nb)
{
	int	count;

	count = 0;
	while ((nb / 10) > 9)
	{
		count++;
		nb = (nb / 10);
	}
	count++;
	return (count);
}

int     ft_numlen_hexa(int nb)
{
        int     count;

        count = 0;
        while ((nb / 16) > 15)
        {
                count++;
                nb = (nb / 16);
        }
        count++;
        return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}

	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == INT_MIN)
		return (write(1, "INT_MIN", 11));
	if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		nb = (nb * -1);
	}
	if ((nb / 10) != 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10);
	return (count + ft_numlen(nb));
}

int	ft_putnbr_hexa(unsigned int nb)
{
	if ((nb / 16) > 15)
		nb = (nb / 16);
	if ((nb % 16) > 9)
		nb = ((nb % 16) + 87);
	if ((nb % 16) <= 9)
		nb = ((nb % 16) + 48);
	return (ft_numlen_hexa(nb));
}

void	type_selector(char *str, s_print *p_data)
{
	if (str[0] == 'd')
		p_data->count = p_data->count + ft_putnbr(va_arg(p_data->valist, int));
	if (str[0] == 'x')
		 p_data->count = p_data->count + ft_putnbr_hexa(va_arg(p_data->valist, unsigned long));
	if (str[0] == 's')
		 p_data->count = p_data->count + ft_putstr(va_arg(p_data->valist, char *));
}


int	ft_printf(char *str, ...)
{
	s_print	data;
	int	i;

	i = 0;
	data.count = 0;
	va_start(data.valist, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			type_selector(&str[i], &data);
		}
		else
		{
			write(1, &str[i], 1);
			data.count++;
		}
		i++;
	}
	va_end(data.valist);
	return (data.count);
}


int     main(void)
{
        int     n;
        int     n_hexa;
        char    *str;

        n = 30;
        n_hexa = 4728;
        str = "Bonjour";

        ft_putnbr(ft_printf("%s, Je suis Thomas\n", str));
        ft_putnbr(ft_printf("J ai %d ans\n", n));
        ft_putnbr(ft_printf("En hexa sa fait : %x\n", n_hexa));
        return (0);
}
