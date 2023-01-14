/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:39:53 by juan-aga          #+#    #+#             */
/*   Updated: 2022/09/22 15:30:34 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *srch, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	len_srch;

	i = 0;
	if (srch[i] == '\0')
		return ((char *)str);
	len_srch = ft_strlen(srch);
	while (i < len && str[i] != '\0')
	{
		i2 = 0;
		while (srch[i2] == str[i + i2] && i2 + i < len)
		{
			if (i2 == len_srch -1)
				return ((char *)&str[i]);
			i2++;
		}
		i++;
	}
	return (NULL);
}
