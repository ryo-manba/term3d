#include "term3d.h"
#include <string.h>

// Number of elements for the keyword
# define OBJ_NAME    1
# define OBJ_GROUP   1
# define OBJ_MTLLIB  1
# define OBJ_COMMENT 1
# define OBJ_USEMTL  1
# define OBJ_SMOOTH_SHADING 1
# define OBJ_VERTEX_TEXTURE 2
# define OBJ_VERTEX_NORMAL_VECTOR    3
// Polygon data is only supported for triangles
# define OBJ_POLYGONAL_SUFACE_DATA   3
# define OBJ_VERTEX_COORDINATE_VALUE 3
# define OBJ_NONEXISTENT_KEYWORD -1


// objfile
int 	check_obj_type(const char *keyword);
bool	check_line_obj(const char **lines);

// 3dfile
bool	check_line_3d(const char **lines);

