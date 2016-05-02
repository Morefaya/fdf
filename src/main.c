#include "fdf.h"

static int	draw(t_win *win)
{
	int	i;
	int	j;
	t_pos	a;
	t_pos	b;
	int	d;
	int	e;

	a.x = 100;
	a.y = 200;
	b.x = 300;
	b.y = 400;

	d = (a.x - b.x) / (a.y - b.y);
	e = a.y / (a.x * d);
	i = a.x;
	while (i < b.x)
	{
		j = d * i + e;
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, i, j, BLUE);
		i++;
	}
	return (0);
}

static int	keyboard(int key, t_win *win)
{
	if (key == 53)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	else
		ft_putnbr(key);
		ft_putchar('\n');	
	return (0);
}

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
