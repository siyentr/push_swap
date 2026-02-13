/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:10:00 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/13 05:12:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static const char	*skip_space(const char *cursor)
{
	while (ft_isspace(*cursor))
		cursor++;
	return (cursor);
}

static void	parse_sign(const char **cursor, int *sign)
{
	*sign = 1;
	if (**cursor == '+' || **cursor == '-')
	{
		if (**cursor == '-')
			*sign = -1;
		(*cursor)++;
	}
}

static int	parse_number(const char **cursor, int sign, int *out)
{
	long long	value;
	int			digit_found;

	value = 0;
	digit_found = 0;
	while (**cursor >= '0' && **cursor <= '9')
	{
		value = value * 10 + (**cursor - '0');
		digit_found = 1;
		if (sign == 1 && value > INT_MAX)
			return (-1);
		if (sign == -1 && - value < INT_MIN)
			return (-1);
		(*cursor)++;
	}
	if (!digit_found)
		return (-1);
	*out = (int)(value * sign);
	return (0);
}

int	parse_int(const char *str, int *out)
{
	const char	*cursor;
	int			sign;

	if (!str || !out)
		return (-1);
	cursor = skip_space(str);
	parse_sign(&cursor, &sign);
	if (parse_number(&cursor, sign, out) != 0)
		return (-1);
	cursor = skip_space(cursor);
	if (*cursor != '\0')
		return (-1);
	return (0);
}
