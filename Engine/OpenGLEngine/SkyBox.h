#ifndef SKYBOX_H
#define SKYBOX_H
#include "ShaderProgram.h"

using namespace std;
using namespace glm;
class SkyBox
{
public:
	SkyBox();
	~SkyBox();
	
	unsigned int cubeMap;

	void loadCubemap(vector<string> faces);
	void DrawSkyBox(ShaderProgram shader, Camera camera, glm::mat4 project);
private:

	unsigned int skyBoxVAO, skyBoxVBO;

	
};
#endif
