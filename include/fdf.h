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

# define BLUE 0x000000ff

typedef struct	s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_win;

#endif
