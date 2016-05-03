#include "fdf.h"

static int	draw(t_win *win)
{
	t_pos	i;
	t_pos	a;
	t_pos	b;
	double	d;
	double	e;

	a.x = 145;
	a.y = 156;
	b.x = 400;
	b.y = 156;
	if (a.x != b.x)
	{
		d = (a.y - b.y) / (a.x - b.x);
		e = a.y - d * a.x;
		i.x = (a.x < b.x) ? a.x : b.x;
		while (i.x < ((a.x < b.x) ? b.x : a.x))
		{
			i.y = d * i.x + e;
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, i.y, BLUE);
			i.x++;
		}
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, a.x, a.y, RED);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, b.x, b.y, GREEN);
	}
	else
	{
		i.x = a.x;
		i.y = (a.y <= b.y) ? a.y : b.y;
		while (i.y < ((a.y < b.y) ? b.y : a.y))
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, i.y, BLUE);
			i.y++;
		}
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, a.x, a.y, RED);
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, b.x, b.y, GREEN);
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
