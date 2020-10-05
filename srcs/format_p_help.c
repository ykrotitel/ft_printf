/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:55:27 by atote             #+#    #+#             */
/*   Updated: 2019/12/22 20:20:35 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		init_16_mas(char *hex)
{
	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
}

void		const_p_second(t_params *m, char *res)
{
	if (m->f_check_presicion < m->f_check_width && ft_strlen(res) > 1)
	{
		while (res[m->i] == '0')
			m->i--;
		if (m->i != -1)
			res[m->i + 1] = '\0';
	}
	if (ft_strlen(res) <= 1 && (m->f_check_presicion == -1))
		res[0] = '\0';
}

void		const_p(t_params *m, char *res)
{
	if (m->f_check_presicion != 0)
	{
		if (m->f_check_presicion > (m->i))
		{
			while (m->f_check_presicion - m->i > 0)
			{
				res[m->i] = '0';
				m->i++;
			}
			res[(m->i--)] = '\0';
		}
		else if (m->f_check_presicion >= m->f_check_width)
		{
			m->i = m->f_check_presicion;
			res[m->i + 1] = '\0';
		}
	}
	const_p_second(m, res);
}

void		ft_putstrrev_o8(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		ft_putchar2(src[i]);
		i--;
	}
}

int			ft_check_minus(char *line, int i)
{
	while (ft_check_all_flags(line, i))
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
