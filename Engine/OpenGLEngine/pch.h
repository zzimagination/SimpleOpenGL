#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <ctime>
#include <fstream>
#include <iostream>
#include <malloc.h>
#include <memory.h>
#include <random>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <tchar.h>
#include <windows.h>

#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "stb_image.h"

#define SCR_WIDTH  1920
#define SCR_HEIGHT  1080

#endif // !PCH
