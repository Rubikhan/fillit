/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:03:33 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/24 17:34:07 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void	dono_error(int a)
{
	if (a == 1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	else if (a == 0)
	{
		ft_putstr("usage: tetromino_file\n");
		exit(0);
	}
	else
		ft_putstr("dono_error called O_O\n");
}
