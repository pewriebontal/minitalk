/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:47:53 by mkhaing           #+#    #+#             */
/*   Updated: 2023/11/20 07:36:08 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>
# include <sys/types.h>

char	*ft_char_to_binary(char c);
char	ft_binary_to_char(const char *binary);

#endif