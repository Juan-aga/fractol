/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:35:00 by juan-aga          #+#    #+#             */
/*   Updated: 2022/09/24 19:12:40 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		if (s_len - start > len)
			str = (char *) ft_calloc(len + 1, sizeof(char));
		else
			str = (char *) ft_calloc(s_len - start + 1, sizeof(char));
		if (!str)
			return (NULL);
		if (len + 1 == 0)
			len--;
		ft_strlcpy(str, &s[start], len + 1);
	}
	else
		str = (char *) ft_calloc(1, sizeof(char));
	return (str);
}
