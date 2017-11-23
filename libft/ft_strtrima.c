/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:45:56 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/05 14:34:12 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrima(char const *s, int a)
{
	size_t	i;
	size_t	begin;
	size_t	terminus;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == a))
		i++;
	if (!s[i])
		return (ft_strnew(0));
	begin = i;
	while (s[i])
		i++;
	i--;
	while (s[i] == a)
		i--;
	terminus = i + 1;
	str = ft_strnew(terminus - begin);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, &s[begin], terminus - begin);
	return (str);
}
