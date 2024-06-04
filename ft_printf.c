/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:50:17 by kepouliq          #+#    #+#             */
/*   Updated: 2024/06/04 18:49:51 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char c, va_list args)
{
	if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
	{
		return (put_str(va_arg(args, char *)));
	}
	else if (c == 'd' || c == 'i')
	{
		return (put_int(va_arg(args, int)));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length_return;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	length_return = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length_return += check_format(str[i], args);
		}
		else
			length_return += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (length_return);
}

//------------------------------------------------------------------------
/*
	//TEST POUR %C

int main()
{
	char c = 'k';
	printf("%d\n", ft_printf("%cda\n",c));
	
	printf("%d\n", printf("%cda\n", c));
	return (0);
}*/

//------------------------------------------------------------------------
/*
	//TEST POUR %%

int main()
{
	ft_printf("%%\n");
	printf("%%\n");
	return(0);
}*/

//------------------------------------------------------------------------
/*
	//TEST POUR %s

int main()
{
	char *str = "kelian test 123456 .,,']3875y super";
	printf("%d\n", ft_printf("%s\n",str));
	
	printf("%d\n", printf("%s\n", str));
	return (0);
}*/

//------------------------------------------------------------------------
/*
	//TEST POUR %d

int main()
{
	int test = INT_MIN;
	printf("%d\n", ft_printf("%d",test));
	
	printf("%d\n", printf("%d", test));
	return (0);
}*/
