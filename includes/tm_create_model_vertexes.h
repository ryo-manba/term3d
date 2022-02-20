#ifndef TM_CREATE_MODEL_VERTEXES_H
# define TM_CREATE_MODEL_VERTEXES_H

#include "tm_wrapper.h"
#include "tm_utils.h"
#include "term3d.h"

#define OBJ_COMMENT 1
#define OBJ_NAME 1
#define OBJ_SMOOTH_SHADING 1
#define OBJ_MTLLIB 1
#define OBJ_GROUP 1
#define OBJ_USEMTL 1
#define OBJ_VERTEX_COORDINATE_VALUE 3
#define OBJ_VERTEX_TEXTURE 2
#define OBJ_VERTEX_NORMAL_VECTOR 3
#define OBJ_POLYGONAL_SUFACE_DATA 3 // ポリゴンデータは三角の場合のみ対応
#define OBJ_NONEXISTENT_KEYWORD -1

t_vertex	*create_model_vertexes(const char *file_data, const char delimiter);

#endif
