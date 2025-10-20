/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:27:01 by codespace         #+#    #+#             */
/*   Updated: 2025/10/17 11:59:32 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3000
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

char	*ft_strdup_gnl(const char *s1);
char	*ft_strchrmod(const char *s, int c);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*end_of_line(char *buff);
char	*get_next_line(int fd);

#endif
