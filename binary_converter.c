/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:28:31 by mkhaing           #+#    #+#             */
/*   Updated: 2023/11/20 07:36:43 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_binary_to_char(const char *binary)
{
	char	result;
	int		i;

	result = 0;
	i = 0;
	while (i < 8 && binary[i] != '\0')
	{
		result = (result << 1) + (binary[i] - 48);
		i++;
	}
	return (result);
}

char	*ft_char_to_binary(char c)
{
	int		i;
	char	*binary;

	binary = (char *)malloc(9);
	if (!binary)
	{
		return (NULL);
	}
	binary[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		binary[i] = (c & 1) + 48;
		c >>= 1;
		i--;
	}
	return (binary);
}
