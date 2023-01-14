/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:03:09 by juan-aga          #+#    #+#             */
/*   Updated: 2022/09/21 19:53:04 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_cpy;
	char		*dst_cpy;

	src_cpy = (const char *) src;
	dst_cpy = (char *) dst;
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			dst_cpy[len] = src_cpy[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
