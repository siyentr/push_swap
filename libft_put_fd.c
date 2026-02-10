/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:42:37 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 14:47:34 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putlong_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putlong_fd(n / 10, fd);
	c = (char)('0' + (n % 10));
	write(fd, &c, 1);
}

void	ft_putdisorder_pct_fd(double disorder, int fd)
{
	long	scaled;
	long	whole;
	long	frac;
	char	c;

	scaled = (long)(disorder * 10000.0 + 0.5);
	whole = scaled / 100;
	frac = scaled % 100;
	ft_putlong_fd(whole, fd);
	write(fd, ".", 1);
	c = (char)('0' + (frac / 10));
	write(fd, &c, 1);
	c = (char)('0' + (frac % 10));
	write(fd, &c, 1);
	write(fd, "%", 1);
}
