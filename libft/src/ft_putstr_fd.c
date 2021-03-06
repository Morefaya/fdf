/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:57:06 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/07 12:55:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	if (str && fd >= 0)
	{
		while (*str)
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
}
