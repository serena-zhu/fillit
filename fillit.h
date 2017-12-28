/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:08:14 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/07 13:36:54 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define VB_VARS int i; int tmp; int offset; int count[2]; int all_pieces_touch

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef	struct	s_block
{
	char		id;
	int			*loc;
}				t_block;

void			exit_with_error(char e);
void			format_blocks(char *buf, t_block *blocks);
void			solve(t_block *blocks, int n);
int				fill_board(char *board, t_block *blocks, int *c);
void			backward(char *board, t_block *blocks, int *c);
#endif
