/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:24:21 by jde-orma          #+#    #+#             */
/*   Updated: 2024/01/24 17:24:21 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_gettime();
	while ((ft_gettime() - start) < milliseconds)
		usleep(500);
	return (0);
}