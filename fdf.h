/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:42:15 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 18:53:31 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define BUFF_SIZE 100

# define PXL 	t_pxl
# define ENV	t_env

typedef struct s_pxl 	t_pxl;
typedef struct s_env	t_env;

struct 		s_pxl
{
	int 	x;
	int 	y;
	int 	z;
	char	*color;
	};

struct		s_env
{
	void 	*mlx;
	void	*win;

	int		l_nbr;
	int		c_nbr;

	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		Dx;
	int		Dy;
	int		x_incr;
	int		y_incr;
};

// FDF			*ft_fill_struct_pxl(FDF *fdf, int fd);
// PXL			*ft_create_pxl(FDF *fdf, int pxl_info[3]);
// FDF			*ft_create_fdf(void);
// PXL			*ft_add_pxl(FDF *fdf, int pxl_info[3]);
// void		ft_destroy_struct(FDF *fdf);
// void		iniatilizing_bresenham(FDF *data);
// ISO			iso_conversion(PXL *pxl);

#endif
