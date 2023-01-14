/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:33:03 by juan-aga          #+#    #+#             */
/*   Updated: 2022/12/11 11:14:35 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"

char	*ft_chrjoin(char *s1, char c)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = ft_calloc(len + 2, sizeof(char));
	if (s2 == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(s2, s1, len + 1);
	s2[len] = c;
	s2[len + 1] = '\0';
	free(s1);
	return (s2);
}
