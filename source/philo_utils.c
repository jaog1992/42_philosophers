/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:30:00 by jde-orma          #+#    #+#             */
/*   Updated: 2024/06/16 11:30:00 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	numb;
	int	flag;

	i = 0;
	flag = 0;
	sign = 1;
	numb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while ((str[i] == '+' || str[i] == '-') && flag == 0)
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
		flag = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (str[i] - '0') + (numb * 10);
		i++;
	}
	return (numb * sign);
}

int	ft_print_red(char *s)
{
	return (printf("\033[0;91m%s\033[0;97m\n", s));
}

int	ft_print_error(char *s)
{
	int	i;

	i = 0;
	i += ft_print_red("Error");
	i += printf("%s", s);
	return (i);
}