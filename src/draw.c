#include "fdf.h"
#include <stdlib.h>

static void	trans_o(t_origin *my_o, t_screen next_pos)
{
	my_o->o.x = next_pos.x;
	my_o->o.y = next_pos.y;
	my_o->i.x = my_o->o.x + UNIT_L;
	my_o->i.y = my_o->o.y;
	my_o->j.x = my_o->o.x;
	my_o->j.y = my_o->o.y - UNIT_L;
	my_o->k.x = my_o->o.x - UNIT_L * ANGLE_R;
	my_o->k.y = my_o->o.y + UNIT_L * ANGLE_R;
}

int	draw(t_win *win)
{
	t_origin	*my_o;
	t_screen	next;
	void		*img_ptr;

	if (!(my_o = (t_origin*)malloc(sizeof(*my_o))))
	{
		ft_putstr("error malloc");
		exit(1);
	}
	my_o->o.x = X_MAX / 4;
	my_o->o.y = Y_MAX / 2;
	my_o->i.x = my_o->o.x + UNIT_L;
	my_o->i.y = my_o->o.y;
	my_o->j.x = my_o->o.x;
	my_o->j.y = my_o->o.y - UNIT_L;
	my_o->k.x = my_o->o.x - UNIT_L * ANGLE_R;
	my_o->k.y = my_o->o.y + UNIT_L * ANGLE_R;

	next.x = 1000;
	next.y = 300;

	draw_trandmark(win, my_o);
	img_ptr = mlx_new_image(win->mlx_ptr, X_MAX , Y_MAX);

	del_trandmark(win, my_o);
	trans_o(my_o, next);
	draw_trandmark(win, my_o);

	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img_ptr, X_MAX, Y_MAX);
	/*t_screen	o;
	t_pos		c;

	c.x = 1;
	c.y = 1;
	c.z = 1;
	get_pixel(c, my_o, &o);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, o.x, o.y, YELLOW);
	c.x = 0;
	c.y = 1;
	c.z = 0;
	get_pixel(c, my_o, &o);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, o.x, o.y, YELLOW);
	c.x = 1;
	c.y = 0;
	c.z = 0;
	get_pixel(c, my_o, &o);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, o.x, o.y, YELLOW);
	c.x = 0;
	c.y = 0;
	c.z = 1;
	get_pixel(c, my_o, &o);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, o.x, o.y, YELLOW);
	c.x = 1;
	c.y = 1;
	c.z = 0;
	get_pixel(c, my_o, &o);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, o.x, o.y, YELLOW);
	c.x = 1;
	c.y = 0;
	c.z = 1;
	get_pixel(c, my_o, &o);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, o.x, o.y, YELLOW);
	c.x = 0;
	c.y = 1;
	c.z = 1;
	get_pixel(c, my_o, &o);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, o.x, o.y, YELLOW);*/
	return (0);
}
