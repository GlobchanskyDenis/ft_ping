#ifndef STRCONV_H
# define STRCONV_H

/*  Данная библиотека содержит только функции конвертирования
**	числа в строку и наоборот  */

/*	Там содрежатся стандартные функции общего назначения. Например isdigit  */
# include "common.h"
/*	Содержит типы данных (например size_t)  */
# include <stddef.h>

int			ft_atoi_base(const char *str, int base);
int			ft_atoi(const char *str);
long long	ft_atoll(char const *s);
char		*ft_itoa(int n);
char		*ft_szttoa(size_t n);
char		*ft_ulltoa_base(unsigned long long dgt, int base);

#endif
