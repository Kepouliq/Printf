/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:08:27 by kepouliq          #+#    #+#             */
/*   Updated: 2024/06/04 18:51:28 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
int		put_str(char const *str);
size_t	ft_strlen(const char *s);
int		put_int(int nb);
void	ft_putchar(char c);

#endif