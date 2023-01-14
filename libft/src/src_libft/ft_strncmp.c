/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:05:52 by juan-aga          #+#    #+#             */
/*   Updated: 2022/09/22 13:26:51 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != '\0' && (unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((int)(unsigned char)s1[i] -(unsigned char)s2[i]);
	}
	return ('\0');
}
