/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:09:57 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/10/17 11:03:33 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct map{
    char *NO_texture;
    char *SO_texture;
    char *WE_texture;
    char *EA_texture;
    char *F_colour;
    char *C_colour;
} t_map;

t_map	*parse_crossroad(char *argv, t_map *map);
int     parsing_elements(char *line, t_map *map);

#endif