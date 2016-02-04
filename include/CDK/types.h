#ifndef __H_TYPES__
#define __H_TYPES__
#include <stdint.h>
#include "glm\glm.hpp"


#define __WINDOWS_PLATFORM__
#ifdef __WINDOWS_PLATFORM__

typedef signed char int8 ;
typedef int int32;
typedef unsigned int uint32;
typedef char int16;


typedef glm::vec3 vec3;
typedef glm::mat4 mat4;
#endif








#endif