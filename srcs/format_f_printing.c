/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f_printing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:50:40 by atote             #+#    #+#             */
/*   Updated: 2019/12/15 19:32:57 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_with_precision(char *res, int i, t_params *m)
{
	int	k;

	k = 0;
	if (m->f_check_octotorp && m->f_check_presicion < 1)
	{
		ft_putchar2('.');
		m->f_check_width = m->f_check_width - 1;
	}
	while (--i >= -1 && (m->type == 9 || m->type == 91 || m->type == 911))
	{
		if (k > 82)
			ft_putchar2('0');
		else
			ft_putchar2(res[k++]);
	}
	print_with_precision_e(res, m->ff, m->type);
	while (--i >= -1 && m->type == 92)
	{
		if (res[k] != '0')
			ft_putchar2(res[k++]);
	}
	free(res);
}

void	w_nominus_print_f(t_params *m, char *res, int *len)
{
	if ((m->f_check_width = m->f_check_width - *len) > 0)
	{
		if ((m->f_check_zero) && (1 / m->doubl < 0))
		{
			ft_putchar2('-');
			m->long_long_in = m->long_long_in * -1;
			if (m->long_long_in == 0)
				m->f_check_width--;
		}
		if (m->f_check_zero && m->f_check_space && m->doubl > 0)
		{
			ft_putchar2(' ');
			m->f_check_width = m->f_check_width - 1;
		}
		while (--(m->f_check_width) >= 0)
		{
			if (m->f_check_zero)
				ft_putchar2('0');
			else
				ft_putchar2(' ');
		}
	}
	else if (m->f_check_space && !m->f_check_plus &&
			!m->f_check_minus && m->long_long_in > 0)
		ft_putchar2(' ');
}

void	w_minus_print_f(t_params *m, char *res, int *len)
{
	if (m->f_check_plus && 1 / m->doubl > 0)
		ft_putchar2('+');
	res = okruglenie(res, m->f_check_value_precision, m);
	if (m->f_check_space && !m->f_check_plus && m->doubl > 0)
	{
		ft_putchar2(' ');
		m->f_check_width = m->f_check_width - 1;
	}
	ft_putlonglong2(m->long_long_in);
	print_with_precision(res, m->f_check_value_precision, m);
	if ((m->f_check_width = m->f_check_width - *len) > 0)
	{
		while (--(m->f_check_width) >= 0)
			ft_putchar2(' ');
	}
}

void	no_width_print_f(t_params *m, char *res)
{
	res = okruglenie(res, m->f_check_value_precision, m);
	if (m->f_check_space && !m->f_check_minus && !m->f_check_plus)
		ft_putchar2(' ');
	if (1 / m->doubl < 0 && m->long_long_in == 0)
		ft_putchar2('-');
	if (m->f_check_plus && 1 / m->doubl > 0)
		ft_putchar2('+');
	ft_putlonglong2(m->long_long_in);
	print_with_precision(res, m->f_check_value_precision, m);
}

void	print_format_f(t_params *m, char *res)
{
	int	len;

	len = check_len_f(m);
	if (m->f_check_width)
	{
		if (m->f_check_minus)
			w_minus_print_f(m, res, &len);
		else
		{
			if (m->f_check_zero && m->f_check_plus &&
					m->long_long_in >= 0 && 1 / m->doubl > 0)
				ft_putchar2('+');
			w_nominus_print_f(m, res, &len);
			if (m->f_check_zero != 1 && m->f_check_plus && m->long_long_in >= 0)
				ft_putchar2('+');
			res = okruglenie(res, m->f_check_value_precision, m);
			ft_putlonglong2(m->long_long_in);
			print_with_precision(res, m->f_check_value_precision, m);
		}
		return ;
	}
	no_width_print_f(m, res);
}
