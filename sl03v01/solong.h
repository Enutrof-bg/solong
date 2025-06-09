/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:30:34 by kevwang           #+#    #+#             */
/*   Updated: 2025/05/26 15:30:35 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define HEIGHT 720
# define WIDTH 480
# define TILE_SIZE 64

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307

# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img_grass;
	char	*dest_grass;
	void	*img_wall;
	char	*dest_wall;
	void	*img_char;
	char	*dest_char;
	void	*img_key;
	char	*dest_key;
	void	*img_exit;
	char	*dest_exit;
	void	*img_exit_open;
	char	*dest_exit_open;
	void	*img_ennemy;
	char	*dest_ennemy;
	void	*img_ennemy_mort;
	char	*dest_ennemy_mort;
	int		width;
	int		height;
}t_image;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		count_e;
	int		count_p;
	int		count_c;
	int		map_length;
	int		map_height;
	int		player_x;
	int		player_y;
	int		ennemy_x;
	int		ennemy_y;
	int		ennemy_mort_x;
	int		ennemy_mort_y;
	int		player_collect;
	int		player_end;
	int		exit_x;
	int		exit_y;
	t_image	img;
}t_data;

//solong_utils.c
char	*ft_strdup(char *s);

//ft_split.c
char	**ft_split(char const *s, char c);

//ft_itoa.c
char	*ft_itoa(int n);

//ft_printf
int		ft_printf(const char *str, ...);

//map_check.c
void	ft_map_check(t_data *data, char *filename);

//map_check_compo.c
void	ft_map_size(t_data *data, char **map);
int		ft_map_test_wall(t_data *data);
int		ft_map_check_components_double(t_data *data);
int		ft_map_check_components(t_data *data);

//map_check_free.c
void	ft_map_invalid(char **map);
void	ft_free_double_tab(char **tab);

//map_check_open.c
char	*ft_open(t_data *data, char *filename);
int		ft_check_filename(char *filename);
char	**ft_open_map(t_data *data, char *filename);

//map_check_path.c
char	**ft_copy_double_char(char **tab);
void	ft_map_path_set(char **map, int i, int j);
void	ft_map_path(t_data *data, char **map);
int		ft_map_key_path(char **map);
int		ft_check_path(t_data *data);

//solong_free.c
int		on_destroy(t_data *data);

//solong_init.c
void	set_img(t_data *data);
void	ft_printf_map(t_data *data);

//solong_init_xpm.c
void	ft_get_img_grass(t_data *data);
void	ft_get_img_wall(t_data *data);
void	ft_get_img_char(t_data *data);
void	ft_get_img_key(t_data *data);
void	ft_get_img_exit(t_data *data);

//solong_init_xpm2.c
void	ft_get_img_exit_open(t_data *data);

//solong_move.c
int		ft_move_up(t_data *data);
int		ft_move_down(t_data *data);
int		ft_move_left(t_data *data);
int		ft_move_right(t_data *data);
int		on_keypress(int keysym, t_data *data);

//solong_print_img.c
void	print_img_grass(t_data *data, t_image *img, int x, int y);
void	print_img_wall(t_data *data, t_image *img, int x, int y);
void	print_img_char(t_data *data, t_image *img, int x, int y);
void	print_img_key(t_data *data, t_image *img, int x, int y);
void	print_img_exit(t_data *data, t_image *img, int x, int y);

//solong_print_img2.c
void	print_img_exit_open(t_data *data, t_image *img, int x, int y);

//solong_init_xpm_bonus.c
void	ft_get_img_ennemy(t_data *data);
void	ft_get_img_ennemy_mort(t_data *data);

//solong_move_ennemy_bonus.c
void	ft_set_ennemy(t_data *data);
void	ft_ennemy_move(t_data *data);

//solong_move_ennemy_mort_bonus.c
void	ft_set_ennemy_mort(t_data *data);
void	ft_ennemy_move_mort(t_data *data);

//solong_print_ennemy_bonus.c
void	print_img_ennemy(t_data *data, t_image *img, int x, int y);
void	print_img_ennemy_mort(t_data *data, t_image *img, int x, int y);
void	ft_move_all_ennemy(t_data *data);
void	ft_check_dead(t_data *data);

#endif