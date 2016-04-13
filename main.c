/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:14:41 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/13 14:02:50 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *s)
{
	if (s == NULL)
		perror("error");
	else
	{
		ft_putstr("error: ");
		ft_putstr(s);
		ft_putstr(".\n");
	}
	exit(-1);
}

int		main(int ac, char **av)
{
	ENV		*env;

	if (ac == 2)
	{
		if ((env = (ENV*)malloc(sizeof(ENV))) == NULL)
			ft_error("malloc failed");
		parsing(env, av[1]);
		if ((env->mlx = mlx_init()) == NULL)
			ft_error("mlx_init failed");
		if ((env->win = mlx_new_window(env->mlx, 1366, 768, "FDF")) == NULL)
			ft_error("mlx_new_window failed");
		iso_conversion(env);
		tracing_lines(env);
		tracing_columns(env);
		mlx_key_hook(env->win, &key_binding, env);
		mlx_loop(env->mlx);
	}
	else if (ac > 2)
		ft_error("too much file arguments. Please precise only one file");
	else
		ft_error("not enough file arguments. Please precise at least one file");
	return (0);
}
