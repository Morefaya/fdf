#include "fdf.h"

int	main(void)
{
	t_win	win;

	if (!(win.mlx_ptr = mlx_init()))
	{
		ft_putstr("error init");
		return (1);
	}
	if (!(win.win_ptr = mlx_new_window(win.mlx_ptr, X_MAX, Y_MAX, "yolo")))
	{
		ft_putstr("error new window");
		return (2);
	}
	mlx_expose_hook(win.win_ptr, draw, &win);
	mlx_key_hook(win.win_ptr, keyboard, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
