/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:26:38 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/23 00:31:01 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int check_avail_tiny(char *dono, char *grid, int a, int grid_size)
{
    int w;
    int z;
    int y;
    int x;
    y = ft_strlen(grid);
    z = 0;
    x = 0;
    w = 0;
    while(dono[z] && a < y)
    {
        if(dono[z] == '.' && dono[z - 1] > 64)
        {
            z++;
        }
        if((a + 1) % (grid_size + 1) == 0 && dono[z] > 64)
            return(0);
        else if ((dono[z] > 64 && grid[a] == '.'))
            x++;
        if(x == 4)
            return (1);
        z++;
        a++;
    }
    return(0);
}



int check_available(char *dono, char *grid, int a, int grid_size)
{
    int w;
    int z;
    int y;
    int x;
    y = ft_strlen(grid);
    z = 0;
    x = 0;
    w = 0;

    if (grid_size <= 3)
        return (check_avail_tiny(dono, grid, a, grid_size));
    while(dono[z] && a < y)
    {
        if(dono[z] == '.' && dono[z - 1] > 64)
        {
            w = grid_size - 4;
            while(w--)
                a++;
        }
        if((a + 1) % (grid_size + 1) == 0 && dono[z] > 64) //pay attention to grid_size
        {
            return(0);
        }
        else if ((dono[z] > 64 && grid[a] == '.'))
            x++;
        if(x == 4)
            return (1);
        z++;
        a++;
    }
    return(0);
}

/* 
** b is unneccesary? just use shift? idkmybffjill 
*/ 

void placeit_tiny(char *dono, char *dono_grid, int shift)
{
    int b;
    int j;
    b = 0;
    j = 0;
    char *y;
    char *x;
    y = dono;
    x = dono_grid;
    while(shift--)
        b++;

    while(y[j])
    {
        if(y[j] == '.' && y[j - 1] > 64)
        {
            j++;
        }
        if(y[j] > 64)
            x[b] = y[j];
        b++;
        j++;
    }
   
}

/*
** place 2nd greater while loop is basically ft_memcpy
*/

void placeit(char* dono, char *dono_grid, int shift, int grid_size)
{
    int z;
    int b;
    int j;
    b = 0;
    j = 0;
    char *y;
    char *x;
    y = dono;
    x = dono_grid;
    while(shift--)
        b++;

    while(y[j])
    {
        if(y[j] == '.' && y[j - 1] > 64)
        {
            z = grid_size - 4;
            while(z--)
                b++;
        }
        if(y[j] > 64)
            x[b] = y[j]; //
        b++;
        j++;
    }
   
}
