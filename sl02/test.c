#include <stdio.h>
#include <unistd.h>

// static int	ft_nbr_len(int nb, int base)
// {
// 	int	i;

// 	i = 1;
// 	while (nb >= base)
// 	{
// 		i++;
// 		nb = nb / base;
// 	}
// 	return (i);
// }

void	ft_putnbr(int nb)
{
	// int	count;

	// count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
		// count++;
	}
	// count = count + ft_nbr_len(nb, 10);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	write(1, &"0123456789"[nb % 10], 1);
	// return (count);
}

void ft_afficher(const char *str, int i, va_list args)
{
	if (str[i + 1] == 'd')
			ft_putnbr(va_arg(args, int));
	if (str[i + 1] == 'c')
		ft_putnbr(va_arg(args, int));
	if (str[i + 1] == 's')
		ft_putnbr(va_arg(args, int));
	if (str[i + 1] == '%')
		write(1, "%", 1);

}

void ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);


	// int i = 0;
	// while (i < n)
	// {
		// printf("%d\n",va_arg(args, int));
		// printf("%c\n",(char)va_arg(args, int));
		// printf("%d\n",va_arg(args, int));
		// printf("%d\n",va_arg(args, int));
		// printf("%d\n",va_arg(args, int));
		// printf("%d\n",va_arg(args, int));
	// 	i++;
	// }

	int i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_afficher(str, i , args);
			i++;
		}	
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
}

int main(void)
{
	// ft_printf("", 11, 't' , 33, 44, 55, 66);
	ft_printf("bonjour %d %%", 11);
}