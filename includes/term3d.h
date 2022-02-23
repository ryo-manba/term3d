/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:28:01 by tkrm              #+#    #+#             */
/*   Updated: 2022/02/23 15:38:25 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define DISPLAY_HEIGHT 40
# define DISPLAY_WIDTH 120
# define DISPLAY_DISTANCE 20
# define FRAMES_PER_SECOND 60 // FPS
# define DEFAULT_CAMERA_MODE 0 // 0:平行投影 1:透視投影
# define OBJ_EXPANSION_RATE 1 // スケール
# define OBJ_ROTATE_SPEED_X 0 // 回転角度
# define OBJ_ROTATE_SPEED_Y 1
# define OBJ_ROTATE_SPEED_Z 0
# define OBJ_PIVOT_X 0 // 回転ピボット
# define OBJ_PIVOT_Y 0
# define OBJ_PIVOT_Z 0
# define CAMERA_POSITION_X 20 // 固定
# define CAMERA_POSITION_Y -5
# define CAMERA_POSITION_Z -80 // 固定
# define CAMERA_EXPANSION_SMOOTH_RATE 120
# define CAMERA_ANGLE_HORIZONTAL 0 // 水平回転角度
# define CAMERA_ANGLE_RANGE 150 // カメラ回転の可動域
# define FILE_TYPE_INVALID -1
# define FILE_TYPE_3D  1
# define FILE_TYPE_OBJ 2
# define FILE_TYPE_INVALID -1
# define MAX_MODEL_SIZE	100

typedef enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}	t_axis;

typedef enum e_camera_mode
{
	PARALLEL,
	PERSPECTIVE
}	t_camera_mode;

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef struct s_vector2
{
	double	x;
	double	y;
}	t_vector2;

typedef struct	s_model
{
	struct s_vertex	 *vertexes;
	struct s_vector3 pivot;
}	t_model;

typedef struct s_vertex
{
	struct s_vector3	position;
	struct s_vertex		*next;
	struct s_vertex		*prev;
	struct s_vertex		*head;
}	t_vertex;

typedef struct s_camera
{
	struct s_vector3	position;
	double				horizontal_angle;
	enum e_camera_mode	mode;
}	t_camera;

char	*read_file(const char *file_path);

#endif
