#include <unistd.h>
#include <stdarg.h>

typedef	struct	s_print
{
	va_list	valist;
	int	count;
}s_print;

int	ft_numlen(int nb)
{
	int	count;

	count = 0;
	while (nb > 9)
	{
		nb = (nb / 10);
		count++;
	}
	count++;
	return  (count);
}

int     ft_numlen_hexa(int nb)
{
        int     count;

        count = 0;
        while (nb > 15)
        {
                nb = (nb / 16);
                count++;
        }
        count++;
        return  (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count = 1;
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return (count + ft_numlen(nb));	
}

int	ft_putnbr_hexa(int nb)
{
	int	count;

	count = 0;
	if ((nb / 16) != 0)
		ft_putnbr_hexa(nb / 16);
	if ((nb % 16) > 9)
		ft_putchar((nb % 16) + 87);
	else
		ft_putchar((nb % 16) + 48);
	return (count + ft_numlen_hexa(nb));
}

void	type_selector(const char *str, s_print *data)
{
	int	i;

	i = 0;
	if (str[i] == 's')
		data->count = data->count + ft_putstr(va_arg(data->valist, char *));
	if (str[i] == 'd')
		data->count = data->count + ft_putnbr(va_arg(data->valist, int));
	if (str[i] == 'x')
		data->count = data->count + ft_putnbr_hexa(va_arg(data->valist, unsigned long));
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

	n = -18346;
	n_hexa = 200;
	str = "Bonjour";
	ft_putnbr(ft_printf("%s, je suis thomas.\n", str));
	ft_putnbr(ft_printf("Numero %d\n", n));
	ft_putnbr(ft_printf("matricule Hexa: %x\n", n_hexa));
	ft_putnbr(ft_printf("%s, je suis thomas. Numero %d. matricule Hexa: %x\n", str, n, n_hexa));
	return(0);
}


