/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:14:41 by juan-aga          #+#    #+#             */
/*   Updated: 2022/09/23 15:24:59 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *) ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(&str[len_s1], s2, len_s2 +1);
	return (str);
}
