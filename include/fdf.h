#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define X_MAX 1200
# define Y_MAX 600

# define ESC 53

# define BLACK 0x0
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000

typedef struct	s_pos
{
	double	x;
	double	y;
}		t_pos;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_win;

#endif
