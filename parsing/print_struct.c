/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:09 by anezka            #+#    #+#             */
/*   Updated: 2026/02/18 16:10:03 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_struct(t_map **map)
{
    int i;

    printf("NO texture: %s\n", (*map)->NO_texture);
    printf("SO texture: %s\n", (*map)->SO_texture);
    printf("EA texture: %s\n", (*map)->EA_texture);
    printf("WE texture: %s\n", (*map)->WE_texture);
    printf("F colour: %d, %d, %d\n", (*map)->F_colour->red, (*map)->F_colour->blue, (*map)->F_colour->green);
    printf("C colour: %d, %d, %d\n", (*map)->C_colour->red, (*map)->C_colour->blue, (*map)->C_colour->green);
    i = 0;
    while ((*map)->map[i] != NULL)
    {
        printf("%s\n", (*map)->map[i]);
        i++;
    }
}