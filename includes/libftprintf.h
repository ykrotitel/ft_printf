/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:36:19 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/24 19:28:39 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define ALWAYS_POZITIVE(x)	(x >= 0 ? x : -x)
# define NALICIE_MINUSA(x) (x < 0 ? 1 : 0)
# define BIGGEST(x,y) (x > y ? x : y)
# define TWO_OR_ZERO(x,y) (x != 0 && y != 0 ? 2 : 0)
# define IS_HUNDRED(x) (x < 100 ? 0 : 1)
# define WHILE_NOT_ZERO(x) (x > 0 ? x - 1 : 0)
# define ISNULL(x) (x == 0 ? 0 : 1)
# define FOR_DIMA 1444565444646
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

int							g_count;

typedef struct				s_params
{
	long int				long_in;
	long long int			long_long_in;
	long long int			p;
	long unsigned int		unsigned_long_in;
	long long unsigned int	unsigned_long_long_in;
	unsigned int			unsigned_in;
	short unsigned int		unsigned_short_in;
	char					cha;
	char					*cha2;
	char					*res;
	char					*manta;
	void					*poin;
	float					flo;
	long double				doubl1;
	char					**res11;
	double					doubl;
	int						isnull;
	int						short_in;
	int						type;
	int						in;
	int						short_short_in;
	int						ff;
	int						i;
	int						number;
	int						len;
	int						f_check_width;
	int						f_check_minus;
	int						f_check_plus;
	int						f_check_star;
	int						f_check_zero;
	int						f_check_presicion;
	int						f_check_octotorp;
	int						f_check_space;
	int						f_otricatelnoe;
	int						f_check_point;
	int						f_check_value_precision;
	int						f_check_long_int;
	int						f_check_short_int;
	int						f_check_j;
	int						j;
	int						f;
	unsigned char			unsigned_char;
	char					*colour;
}							t_params;

void						between_p(char *line, int i,
							va_list a, t_params *m);
void						between_s(char *line, int i,
							va_list a, t_params *m);
void						between_d(t_params *m, char *line,
							int i, va_list a);
void						between_c(t_params *m, int flag,
							va_list a);
void						between(char *line, int i,
							t_params *m, va_list a);
void						take_width_2(char *line, int i,
							t_params *m, va_list a);
void						take_all_params_2(char *line, int i,
							t_params *m, va_list a);
void						recognize_colour(char *res, t_params *m);
void						to_d(char *line, int i, t_params m, va_list a);
void						ox_s(t_params *m, int flag, char *resx, int in);
void						choose_unsigned(t_params *m, int number);
void						choose_int(t_params *m, int number);
void						to_hhu(char *line, int i, t_params m, va_list a);
void						to_hu(char *line, int i, t_params m, va_list a);
void						to_llu(char *line, int i, t_params m, va_list a);
void						to_lu(char *line, int i, t_params m, va_list a);
void						to_u(char *line, int i, t_params m, va_list a);
void						to_hhd(char *line, int i, t_params m, va_list a);
void						to_hd(char *line, int i, t_params m, va_list a);
void						to_lld(char *line, int i, t_params m, va_list a);
void						to_ld(char *line, int i, t_params m, va_list a);
void						print_width_2(t_params *m, int size_number);
void						print_width_1(t_params *m, int size_number, int i);
void						print_p_more(t_params *m, int size_number, int i);
void						print_only_d_u(t_params *m);
int							number_counting_x(long long int nbr);
int							number_counting(size_t in);
int							ft_check_octotorp(char *line, int i);
int							ft_check_plus(char *line, int i);
int							ft_check_short_int(char *line, int i);
int							ft_check_zero(char *line, int i);
int							ft_check_space(char *line, int i);
int							count_flags(char *line, int i);
int							take_width(char *line, int i);
int							take_presicion(char *line, int i);
int							ft_atoi_easy(char *line);
int							ft_check_all_flags(char *line, int i);
int							ft_check_point(char *line, int i);
int							count_flags(char *line, int i);
int							number_counting(size_t in);
int							take_presicion(char *line, int i);
int							ft_check_short_int(char *line, int i);
int							ft_check_point(char *line, int i);
int							ft_check_all_flags(char *line, int i);
int							ft_check_space(char *line, int i);
int							ft_check_zero(char *line, int i);
int							ft_check_octotorp(char *line, int i);
int							ft_check_plus(char *line, int i);
int							ft_check_minus(char *line, int i);
int							ft_check_value(char *line, int i);
int							ft_check_long_int(char *line, int i);
int							ft_check_long_f(char *line, int i);
int							ft_atoi_sharp(const char *nptr);
int							ft_choose_flags(char *line, int i);
int							take_width(char *line, int i);
void						ft_put_choose(t_params *m);
void						to_int(char *line, int i, t_params m, va_list a);
void						take_all_params(char *line, int i, t_params *m);
void						choose_char(t_params *m, int number);
void						ft_put_choose(t_params *m);
void						convert_to_sixteen(char *line, int i, t_params *m);
void						help(char *x, int n, t_params *m, char *line);
void						take_all_params(char *line, int i, t_params *m);
void						print_format_c(t_params *m);
void						print_format_o8(t_params *m);
void						print_format_p(t_params *m);
long double					zero_part(t_params *m, long double doubl1);
void						print_format_str(t_params *m);
void						print_format_d(t_params *m, int size_number);
void						print_with_precision(char *res, int i, t_params *m);
void						format_x(char *line, int i, va_list a, int flag);
void						format_str(char *line, int i, va_list a);
void						format_c(char *line, int i, va_list a, int flag);
void						d_u(char *line, int i, va_list a, t_params m);
void						format_p(char *line, int i, va_list a);
void						format_o8(char *line, int i, va_list a);
void						free_map(char **res11, int index);
void						format_f(char *line, int i, va_list a, int type);
void						print_format_f(t_params *m, char *res);
void						w_nominus_print_f(t_params *m, char *res, int *len);
void						w_minus_print_f(t_params *m, char *res, int *len);
void						no_width_print_f(t_params *m, char *res);
void						vibor_mantiss(long double doubl1, t_params *m);
char						*manta_for_null(char *manta,
							char *manta1, int flag);
void						second_manta_for_null(char *manta1,
							int flag, t_params *m);
int							kratnie5_manta_for_null(char *manta, t_params *m);
void						first_manta_for_null(char *manta1,
							char *manta, t_params *m, int flag);
int							number_counting_in(int in);
int							poryadok(int len);
char						*get_left_space_for_la(char *res, t_params *m);
char						*sdvig(char *res, int k);
char						*long_arif(char *a, char *b, char sign);
char						*get_good_line_of_pre(char *res, t_params *m);
char						*get_allres(char **res11, t_params *m);
char						*bit_fourth(long double res, long long int in);
char						*bit_double(double res, long long int in);
char						*div_bit_double(t_params *m, char *result,
							unsigned char tmp, unsigned char *gg);
char						*get_only_mant(char *res,
							long long int in, int flag);
int							mant_to_byte(long long int mant);
char						*ft_itoa_dr(int a);
void						perenos_okruglenie(char *res, t_params *m, int *k);
char						*okruglenie(char *res, int i, t_params *m);
void						ft_putstrrev(char *src, t_params *m, int in);
void						get_colour_line(char *rescolour, char *begin,
							char *end, char *mid);
void						to_binary(t_params *m, va_list a);
char						*check_colour(char *line, int i);
void						recognize_colour(char *res, t_params *m);
void						get_colour_line(char *rescolour, char *begin,
							char *end, char *mid);
void						goodline_e(t_params *m, char *resnew, int *len);
void						print_with_precision_e(char *res, int ff, int type);
int							check_len_f(t_params *m);
void						init_16_mas(char *hex);
void						const_p(t_params *m, char *res);
void						ft_putstrrev_o8(char *src);
void						ft_putchar2(char c);
void						ft_putstr2(char const *s);
void						ft_putnbr2(int nb);
void						ft_putlonglong2(long long int nb);
void						ft_putunsignedlong2(unsigned long long int nb);
int							ft_check_vl(char c);
int							ft_check_j(char *line, int i);
void						for_help_f(t_params *m);
int							ft_check_star(char *line, int i);
void						print_format_pp(t_params *m, char hex[16],
							char	res[sizeof(m->p) + 3]);
void						format_p_firsthelp(t_params *m, char *res);
int							choose_flags_first_help(char *line, int i);
int							ft_choose_flags_help(char *line, int i);
void						format_ox_fourth_help(t_params *m, int flag);
int							help_ft_printf(char *line, int i);
int							help2_ft_printf(va_list a, int g_count);

#endif
