/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:13:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/14 16:30:45 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		translation(int keycode, ENV *env)
{
	if (keycode == 123)
		env->translate_x -= 5;
	if (keycode == 124)
		env->translate_x += 5;
	if (keycode == 126)
		env->translate_y += 5;
	if (keycode == 125)
		env->translate_y -= 5;
}

static void		zoom(int keycode, ENV *env)
{
	if (keycode == 78)
	{
		if (env->zoom > 1)
			env->zoom -= 5;
		else
			env->zoom = 1;
	}
	if (keycode == 69)
		env->zoom += 5;
}

static void		rotate(int keycode, ENV *env)
{
	if (keycode == 15)
	{
		env->rotate += 5;
		z_rotate(env);
	}
}

int				key_binding(int keycode, ENV *env)
{
	int		i;

	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		i = -1;
		while (++i < env->l_nbr)
			free(env->map[i]);
		free(env->map);
		free(env);
		exit(0);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		translation(keycode, env);
	if (keycode == 78 || keycode == 69)
		zoom(keycode, env);
	if (keycode == 15)
		rotate(keycode, env);
	mlx_clear_window(env->mlx, env->win);
	tracing(env);
	return(0);
}
