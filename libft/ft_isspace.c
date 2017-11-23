/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:59:28 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 15:59:48 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int a)
{
	if (a == ' ' ||
			a == '\t' ||
			a == '\n' ||
			a == '\v' ||
			a == '\f' ||
			a == '\r')
		return (1);
	else
		return (0);
}