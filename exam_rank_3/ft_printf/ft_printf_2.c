#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
typedef struct	s_print
{
	va_list valist;
	int	count;
}s_print;

int	ft_numlen(int nb)
{
	int	count;

	count = 0;
	while (nb > 9)
	{
		count++;
		nb = nb / 10;
	}
	count++;
	return (count);
}

int     ft_numlen_hexa(int nb)
{
        int     count;

        count = 0;
        while (nb > 16)
        {
                count++;
                nb = nb / 16;
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
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = (nb * -1);
		count = 1;
	}
	if ((nb / 10) != 0)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
	return (count + ft_numlen(nb));
}

int	ft_putnbr_hexa(unsigned int nb)
{
	if ((nb / 16) != 0)
		ft_putnbr_hexa(nb / 16);
	if ((nb % 16) > 9)
		ft_putchar((nb % 16) + 87);
	else
		ft_putchar((nb % 16) + 48);
	return (ft_numlen_hexa(nb));
}


void	type_selector(const char *str, s_print *p_data)
{
	int	i;

	i  = 0;
	if (str[i] == 's')
		p_data->count = p_data->count + ft_putstr(va_arg(p_data->valist, char *));
	if (str[i] == 'd')
		p_data->count = p_data->count + ft_putnbr(va_arg(p_data->valist, int));
	if (str[i] == 'x')
		p_data->count = p_data->count + ft_putnbr_hexa(va_arg(p_data->valist, unsigned long));
}
int	ft_printf(const char *str, ...)
{
	s_print data;
	int	i;

	va_start(data.valist, str);
	i = 0;
	data.count = 0;
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

int	main(void)
{
	int	n;
	int	n_hexa;
	char	*str;

	n = INT_MIN;
	n_hexa = 4728;
	str = "Bonjour";

	ft_putnbr(ft_printf("%s, Je suis Thomas\n", str));
	ft_putnbr(ft_printf("J ai %d ans\n", n));
	ft_putnbr(ft_printf("En hexa sa fait : %x\n", n_hexa));
	return (0);
}
