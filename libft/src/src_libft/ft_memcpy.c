/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:49:24 by juan-aga          #+#    #+#             */
/*   Updated: 2022/09/21 19:51:59 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_cpy;
	char	*dst_cpy;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return ("NULL");
	src_cpy = (char *) src;
	dst_cpy = (char *) dst;
	while (i < n)
	{
			dst_cpy[i] = src_cpy[i];
			i++;
	}
	return (dst);
}
