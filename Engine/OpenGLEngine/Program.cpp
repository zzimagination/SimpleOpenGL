#include"pch.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Light.h"
#include "Primitive.h"
#include "ProjectSetting.h"
#include "GameWindow.h"
#include "FrameRuntime.h"
#include "Time.h"

#include "GameLoop.h"
#include "ShaderManager.h"


using namespace glm;
using namespace std;
// camera
Camera camera(vec3(0.0f, 1.0f, 3.0f));

float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float mix = 0.0f;
float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间

float heightScale = 0.5f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void TestScene(GLFWwindow* window);
void ForwardScene(GLFWwindow* window);
void DefferedRender(GLFWwindow* window);
unsigned int loadTexture(char const* path, bool gamma);

int main()
{
	int screenWidth = ProjectSetting::GetWindowWidth();
	int screenHeight = ProjectSetting::GetWindowHeight();
	GameWindow::CreateGameWindow(screenWidth, screenHeight);

	GameWindow::WindowLoop();

	//TestScene(GameWindow::gameWindow);
	//ForwardScene(GameWindow::gameWindow);
	//DefferedRender(GameWindow::gameWindow);

	GameWindow::TerminateGameWindow();
	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	float cameraSpeed = 2.5f * deltaTime; // adjust accordingly
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		camera.ProcessKeyboard(UP, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		camera.ProcessKeyboard(DOWN, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		heightScale += 0.001f;
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		heightScale -= 0.001f;
	}
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {

	float x = (float)xpos;
	float y = (float)ypos;

	if (firstMouse)
	{
		lastX = x;
		lastY = y;
		firstMouse = false;
	}


	float xoffset = x - lastX;
	float yoffset = lastY - y; // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
	lastX = x;
	lastY = y;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll((float)yoffset);
}

unsigned int loadTexture(char const* path, bool gamma)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format, internalFormal;
		if (nrComponents == 1)
		{
			format = GL_RED;
			internalFormal = GL_RED;
		}
		else if (nrComponents == 3)
		{
			format = GL_RGB;
			internalFormal = gamma ? GL_SRGB : GL_RGB;
		}
		else if (nrComponents == 4)
		{
			format = GL_RGBA;
			internalFormal = gamma ? GL_SRGB_ALPHA : GL_RGBA;
		}

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormal, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

unsigned int GetQuad(unsigned int &VBO)
{
	float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
	// positions   // texCoords
	-1.0f,  1.0f,  0.0f, 1.0f,
	-1.0f, -1.0f,  0.0f, 0.0f,
	 1.0f, -1.0f,  1.0f, 0.0f,

	-1.0f,  1.0f,  0.0f, 1.0f,
	 1.0f, -1.0f,  1.0f, 0.0f,
	 1.0f,  1.0f,  1.0f, 1.0f
	};
	unsigned int quadVAO, quadVBO;
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	VBO = quadVBO;
	return quadVAO;
}

void TestScene(GLFWwindow* window)
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	Shader screen("Shader/GL.vs", "Shader/GL.fs");
	Shader GeometryShader("Shader/Geometry.vs", "Shader/Geometry.fs", "Shader/Geometry.gs");
	float points[] = {
		-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // 左上
		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // 右上
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // 右下
		-0.5f, -0.5f, 1.0f, 1.0f, 0.0f  // 左下
	};

	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 20, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 20, (void*)8);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		FrameRuntime::BeginFrame();

		processInput(window);

		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		GeometryShader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_POINTS, 0, 4);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void ForwardScene(GLFWwindow* window)
{
	Primitive cube1(Primitive::cube);
	cube1.SetTransform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 30.0f, 0.0f), glm::vec3(1.0f));
	Primitive cube2(Primitive::cube);
	cube2.SetTransform(glm::vec3(-3.4f, 0.0f, -1.0f), glm::vec3(0, -90, 0), glm::vec3(5.0f, 5, 0.25f));

	Primitive cube3(Primitive::cube);
	cube3.SetTransform(glm::vec3(-1.0f, 0.0f, -3.0f), glm::vec3(0.0f), glm::vec3(1.0f));
	Primitive cube4(Primitive::cube);
	cube4.SetTransform(glm::vec3(1.0f, 0.0f, -3.0f), glm::vec3(0.0f), glm::vec3(1.0f));
	Primitive cube5(Primitive::cube);
	cube5.SetTransform(glm::vec3(0.0f, 0.5f, -5.0f), glm::vec3(0.0f), glm::vec3(1.0f));

	Primitive plane(Primitive::plane);
	plane.SetTransform(glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(10.0f));
	Primitive plane2(Primitive::plane);
	plane2.SetTransform(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(10.0f));

	Primitive lightCube(Primitive::cube);
	lightCube.SetTransform();

	//Model ourModel("unitychan/unitychan.obj");

	unsigned int quadVAO, quadVBO;
	quadVAO = GetQuad(quadVBO);

	vector<string> faces = {
		"Resources/Textures/skybox/right.jpg",
		"Resources/Textures/skybox/left.jpg",
		"Resources/Textures/skybox/top.jpg",
		"Resources/Textures/skybox/bottom.jpg",
		"Resources/Textures/skybox/front.jpg",
		"Resources/Textures/skybox/back.jpg"
	};
	SkyBox skybox;
	skybox.loadCubemap(faces);

	unsigned int whiteTex = loadTexture("Resources/Textures/Texture/White.tga", false);
	unsigned int blackTex = loadTexture("Resources/Textures/Texture/Black.tga", false);
	unsigned int bumpTex = loadTexture("Resources/Textures/Texture/Bump.tga", false);
	unsigned int irregularD = loadTexture("Resources/Textures/Texture/irregular_triangle_curtain_wall_tiles_Base_Color.jpg", true);
	unsigned int irregularN = loadTexture("Resources/Textures/Texture/irregular_triangle_curtain_wall_tiles_Normal.jpg", false);
	unsigned int woodD = loadTexture("Resources/Textures/Texture/american_walnut_crown_cut_Base_Color.jpg", true);
	unsigned int woodN = loadTexture("Resources/Textures/Texture/american_walnut_crown_cut_Normal.jpg", false);
	unsigned int wallD = loadTexture("Resources/Textures/Texture/Soi_RedBricks_Base_Color.jpg", true);
	unsigned int wallN = loadTexture("Resources/Textures/Texture/Soi_RedBricks_Normal.jpg", false);
	unsigned int bg0 = loadTexture("Resources/Textures/Texture/bg1.png", true);


	unsigned int uboMatrices;
	glGenBuffers(1, &uboMatrices);
	glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
	glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));

	Shader unlit("Shader/Shader/Unlit.vs", "Shader/Shader/Unlit.fs");
	unsigned int unlitMatrices = glGetUniformBlockIndex(unlit.ID, "Matrices");
	glUniformBlockBinding(unlit.ID, unlitMatrices, 0);

	Shader lit("Shader/Shader/BlinnPhong.vs", "Shader/Shader/BlinnPhong.fs");
	unsigned int litMatrices = glGetUniformBlockIndex(lit.ID, "Matrices");
	glUniformBlockBinding(lit.ID, litMatrices, 0);
	unsigned int DirLightInfo = glGetUniformBlockIndex(lit.ID, "DirLightInfo");
	glUniformBlockBinding(lit.ID, DirLightInfo, 1);
	unsigned int PointLightInfo = glGetUniformBlockIndex(lit.ID, "PointLightInfo");
	glUniformBlockBinding(lit.ID, PointLightInfo, 2);
	unsigned int SpotLightInfo = glGetUniformBlockIndex(lit.ID, "SpotLightInfo");
	glUniformBlockBinding(lit.ID, SpotLightInfo, 3);

	Shader reflectShader("Shader/Shader/reflect.vs", "Shader/Shader/reflect.fs");
	unsigned int reflectShaderMatrices = glGetUniformBlockIndex(reflectShader.ID, "Matrices");
	glUniformBlockBinding(reflectShader.ID, reflectShaderMatrices, 0);

	Shader refractShader("Shader/Shader/refract.vs", "Shader/Shader/refract.fs");
	unsigned int refractShaderMatrices = glGetUniformBlockIndex(refractShader.ID, "Matrices");
	glUniformBlockBinding(refractShader.ID, refractShaderMatrices, 0);



	Shader hdrFrameBuffer("Shader/Shader/Vertex.vs", "Shader/Shader/HDRColor.fs");
	Shader skyboxShader("Shader/Shader/skybox.vs", "Shader/Shader/skybox.fs");
	Shader simpleDepthShader("Shader/Shader/dir_shadow_mapping_depth.vs", "Shader/Shader/dir_shadow_mapping_depth.fs");
	Shader cubeMapDepthShader("Shader/Shader/point_shadows_depth.vs", "Shader/Shader/point_shadows_depth.fs", "Shader/Shader/point_shadows_depth.gs");

	Shader Gaussian_blur_hori("Shader/Shader/Vertex.vs", "Shader/Shader/Gaussian_blur_hori.fs");
	Shader Gaussian_blur_vert("Shader/Shader/Vertex.vs", "Shader/Shader/Gaussian_blur_vert.fs");
	Shader Bloom("Shader/Shader/Vertex.vs", "Shader/Shader/Bloom.fs");

	Shader Debug("Shader/Shader/Vertex.vs", "Shader/Shader/Fragment.fs");

	Light dirLight(LightType::direction);
	dirLight.position = vec3(5.0f, 7.0f, 5.0f);
	dirLight.direct = vec3(-1, -1.414f, -1);
	dirLight.intensity = 0.3f;
	dirLight.shadow_width = 1024;
	dirLight.shadow_height = 1024;
	dirLight.GetDirLightSpaceMatrix();
	dirLight.SetShaderUBO();


	Light pointLight(LightType::point);
	pointLight.position = vec3(-2.0f, 1.5f, 0.0f);
	pointLight.diffuse = vec3(0.95f, 1.0f, 0.85f);
	pointLight.intensity = 0.7f;
	pointLight.shadow_width = 1024;
	pointLight.shadow_height = 1024;
	pointLight.SetShaderUBO();

	Light spotLight(LightType::spot);
	spotLight.position = vec3(3, 2, 0);
	spotLight.direct = vec3(-1.5f, -2, 0);
	spotLight.diffuse = vec3(0.4f, 0.4f, 1.0f);
	spotLight.intensity = 0;
	spotLight.SetShaderUBO();


#pragma region  阴影纹理



	// configure depth map FBO
	unsigned int dirLightDepthMapFBO;
	glGenFramebuffers(1, &dirLightDepthMapFBO);
	// create depth texture
	unsigned int dirDepthMap;
	glGenTextures(1, &dirDepthMap);
	glBindTexture(GL_TEXTURE_2D, dirDepthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, dirLight.shadow_width, dirLight.shadow_height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	// attach depth texture as FBO's depth buffer
	glBindFramebuffer(GL_FRAMEBUFFER, dirLightDepthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, dirDepthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	unsigned int pointLightDepthMap;
	glGenFramebuffers(1, &pointLightDepthMap);
	unsigned int depthCubemap;
	glGenTextures(1, &depthCubemap);
	glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubemap);
	for (unsigned int i = 0; i < 6; ++i)
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, pointLight.shadow_width, pointLight.shadow_height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindFramebuffer(GL_FRAMEBUFFER, pointLightDepthMap);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthCubemap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
#pragma endregion

#pragma region  后处理
	unsigned int framebufferMultiSampled;
	glGenFramebuffers(1, &framebufferMultiSampled);
	glBindFramebuffer(GL_FRAMEBUFFER, framebufferMultiSampled);
	unsigned int colorBufferMultiSampled;
	glGenTextures(1, &colorBufferMultiSampled);
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, colorBufferMultiSampled);
	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, GL_TRUE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, colorBufferMultiSampled, 0);
	// 将它附加到当前绑定的帧缓冲对象
	unsigned int depthDepthMultiSampled;
	glGenRenderbuffers(1, &depthDepthMultiSampled);
	glBindRenderbuffer(GL_RENDERBUFFER, depthDepthMultiSampled);
	glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthDepthMultiSampled);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	unsigned int intermediateFBO;
	glGenFramebuffers(1, &intermediateFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, intermediateFBO);
	// 生成纹理
	unsigned int colorbuffer;
	glGenTextures(1, &colorbuffer);
	glBindTexture(GL_TEXTURE_2D, colorbuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorbuffer, 0);
	unsigned int depthBuffer;
	glGenRenderbuffers(1, &depthBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	unsigned int HDRFBO;
	glGenFramebuffers(1, &HDRFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, HDRFBO);
	unsigned int hdrSourceColorBuffer;
	glGenTextures(1, &hdrSourceColorBuffer);
	glBindTexture(GL_TEXTURE_2D, hdrSourceColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, hdrSourceColorBuffer, 0);
	unsigned int hdrColorBuffer;
	glGenTextures(1, &hdrColorBuffer);
	glBindTexture(GL_TEXTURE_2D, hdrColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, hdrColorBuffer, 0);
	unsigned int attachments[] = { GL_COLOR_ATTACHMENT0,GL_COLOR_ATTACHMENT1 };
	glDrawBuffers(2, attachments);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	unsigned int BloomFBO;
	glGenFramebuffers(1, &BloomFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, BloomFBO);
	unsigned int bloomColorBuffer;
	glGenTextures(1, &bloomColorBuffer);
	glBindTexture(GL_TEXTURE_2D, bloomColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, bloomColorBuffer, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	unsigned int BlurFBO_0;
	glGenFramebuffers(1, &BlurFBO_0);
	glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_0);
	unsigned int blurColorbuffer_0;
	glGenTextures(1, &blurColorbuffer_0);
	glBindTexture(GL_TEXTURE_2D, blurColorbuffer_0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, blurColorbuffer_0, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	unsigned int BlurFBO_1;
	glGenFramebuffers(1, &BlurFBO_1);
	glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_1);
	unsigned int blurColorbuffer_1;
	glGenTextures(1, &blurColorbuffer_1);
	glBindTexture(GL_TEXTURE_2D, blurColorbuffer_1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, blurColorbuffer_1, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion
	//深度测试
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	////模板测试
	//glEnable(GL_STENCIL_TEST);
	//glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
	//glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	//剔除面
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//glFrontFace(GL_CCW); //逆时针（默认）
	//glFrontFace(GL_CW);//顺时针

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//线框模式

	//glEnable(GL_MULTISAMPLE);

	//glEnable(GL_FRAMEBUFFER_SRGB);
	//glDisable(GL_FRAMEBUFFER_SRGB);
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);


		vec3 oldD = pointLight.position - vec3(0, 1.5f, 0);
		glm::mat4 rotate(1.0);
		rotate = glm::rotate(rotate, radians(45.0f*deltaTime), vec3(0, 1, 0));
		glm::vec3 newD = (rotate)*vec4(oldD, 0);
		newD = newD + vec3(0, 1.5f, 0);
		pointLight.position = newD;
		pointLight.GetCubeShadowTransforms();
		pointLight.SetShaderUBO();

		glBindFramebuffer(GL_FRAMEBUFFER, dirLightDepthMapFBO);
		glViewport(0, 0, dirLight.shadow_width, dirLight.shadow_height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		simpleDepthShader.use();
		simpleDepthShader.setMat4("_dirLightSpaceMatrix", dirLight.GetDirLightSpaceMatrix());
		plane.Draw(simpleDepthShader);
		cube1.Draw(simpleDepthShader);
		cube2.Draw(simpleDepthShader);
		cube3.Draw(simpleDepthShader);
		cube4.Draw(simpleDepthShader);

		glBindFramebuffer(GL_FRAMEBUFFER, pointLightDepthMap);
		glViewport(0, 0, pointLight.shadow_width, pointLight.shadow_height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cubeMapDepthShader.use();
		for (unsigned int i = 0; i < pointLight.cubeShadowTransforms.size(); ++i)
			cubeMapDepthShader.setMat4("_shadowMatrices[" + std::to_string(i) + "]", pointLight.cubeShadowTransforms[i]);
		cubeMapDepthShader.setFloat("_far_plane", pointLight.far_plane);
		cubeMapDepthShader.setVec3("_lightPos", pointLight.position);
		plane.Draw(cubeMapDepthShader);
		cube1.Draw(cubeMapDepthShader);
		cube2.Draw(cubeMapDepthShader);
		cube3.Draw(cubeMapDepthShader);
		cube4.Draw(cubeMapDepthShader);

		glBindFramebuffer(GL_FRAMEBUFFER, framebufferMultiSampled);
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		lit.use();
		lit.setVec3("_viewPos", camera.Position);
		lit.setInt("_dirDepthMap", 0);
		lit.setInt("_pointDepthMap", 1);
		lit.setInt("_material.diffuseTex", 2);
		lit.setInt("_material.normalTex", 3);
		lit.setInt("_material.roughnessTex", 4);
		lit.setFloat("_material.shininess", 64);
		lit.setFloat("_material.specularStrength", 1.0f);
		lit.setVec3("_color", vec3(1, 1, 1));

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, dirDepthMap);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubemap);

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, woodD);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, woodN);
		lit.setFloat("_material.shininess", 256);
		plane.Draw(lit);

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, irregularD);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, irregularN);
		lit.setVec3("_color", vec3(1.0f));
		lit.setFloat("_material.shininess", 32);

		cube1.Draw(lit);

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, wallD);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, wallN);
		cube2.Draw(lit);

		reflectShader.use();
		reflectShader.setVec3("cameraPos", camera.Position);
		reflectShader.setInt("skybox", 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, skybox.cubeMap);
		cube3.Draw(reflectShader);

		refractShader.use();
		refractShader.setVec3("cameraPos", camera.Position);
		refractShader.setInt("skybox", 0);
		cube4.Draw(reflectShader);

		glDepthMask(GL_FALSE);
		glCullFace(GL_FRONT);
		glDepthFunc(GL_LEQUAL);
		skyboxShader.use();
		skybox.DrawSkyBox(skyboxShader, camera, projection);
		glDepthFunc(GL_LESS);
		glCullFace(GL_BACK);
		glDepthMask(GL_TRUE);

		unlit.use();
		unlit.setVec3("_color", dirLight.diffuse*3.0f);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, whiteTex);
		lightCube.SetTransform(dirLight.position, glm::vec3(0), glm::vec3(0.1f));
		lightCube.Draw(unlit);
		unlit.setVec3("_color", pointLight.diffuse*3.0f);
		lightCube.SetTransform(pointLight.position, glm::vec3(0), glm::vec3(0.1f));
		lightCube.Draw(unlit);

		unlit.setVec3("_color", spotLight.diffuse*3.0f);
		lightCube.SetTransform(spotLight.position, glm::vec3(0), glm::vec3(0.1f));
		lightCube.Draw(unlit);


		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glBindFramebuffer(GL_READ_FRAMEBUFFER, framebufferMultiSampled);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, intermediateFBO);
		glBlitFramebuffer(0, 0, SCR_WIDTH, SCR_HEIGHT, 0, 0, SCR_WIDTH, SCR_HEIGHT, GL_COLOR_BUFFER_BIT, GL_NEAREST);


		glBindFramebuffer(GL_FRAMEBUFFER, HDRFBO);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		hdrFrameBuffer.use();
		glBindVertexArray(quadVAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, colorbuffer);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Gaussian_blur_hori.use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, hdrColorBuffer);
		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		unsigned int amount = 10;
		for (unsigned int i = 0; i < amount; i++)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_1);
			Gaussian_blur_hori.use();
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, blurColorbuffer_0);
			glBindVertexArray(quadVAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);

			glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_0);
			Gaussian_blur_vert.use();
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, blurColorbuffer_1);
			glBindVertexArray(quadVAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);
		}

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		Bloom.use();
		Bloom.setInt("scene", 0);
		Bloom.setInt("bloomBlur", 1);
		Bloom.setFloat("exposure", 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, hdrSourceColorBuffer);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, blurColorbuffer_0);

		//Debug.use();
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, colorbuffer);
		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &quadVAO);
	glDeleteBuffers(1, &quadVBO);
	glDeleteFramebuffers(1, &framebufferMultiSampled);
	glDeleteFramebuffers(1, &intermediateFBO);
	glDeleteFramebuffers(1, &dirLightDepthMapFBO);
	glDeleteFramebuffers(1, &pointLightDepthMap);

}



void DefferedRender(GLFWwindow* window)
{

	Primitive cube1(Primitive::cube);
	cube1.SetTransform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 30.0f, 0.0f), glm::vec3(1.0f));
	Primitive cube2(Primitive::cube);
	cube2.SetTransform(glm::vec3(-3.4f, 0.0f, -1.0f), glm::vec3(0, -90, 0), glm::vec3(5.0f, 5, 0.25f));

	Primitive cube3(Primitive::cube);
	cube3.SetTransform(glm::vec3(-1.0f, 0.0f, -3.0f), glm::vec3(0.0f), glm::vec3(1.0f));
	Primitive cube4(Primitive::cube);
	cube4.SetTransform(glm::vec3(1.0f, 0.0f, -3.0f), glm::vec3(0.0f), glm::vec3(1.0f));
	Primitive plane(Primitive::plane);
	plane.SetTransform(glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f), glm::vec3(10.0f));

	Primitive lightCube(Primitive::cube);
	lightCube.SetTransform();

	vector<string> faces = {
	"skybox/right.jpg",
	"skybox/left.jpg",
	"skybox/top.jpg",
	"skybox/bottom.jpg",
	"skybox/front.jpg",
	"skybox/back.jpg"
	};
	SkyBox skybox;
	skybox.loadCubemap(faces);

	unsigned int quadVAO, quadVBO;
	quadVAO = GetQuad(quadVBO);


	unsigned int whiteTex = loadTexture("Texture/White.tga", false);
	unsigned int blackTex = loadTexture("Texture/Black.tga", false);
	unsigned int bumpTex = loadTexture("Texture/Bump.tga", false);
	unsigned int irregularD = loadTexture("Texture/irregular_triangle_curtain_wall_tiles_Base_Color.jpg", true);
	unsigned int irregularN = loadTexture("Texture/irregular_triangle_curtain_wall_tiles_Normal.jpg", false);
	unsigned int woodD = loadTexture("Texture/american_walnut_crown_cut_Base_Color.jpg", true);
	unsigned int woodN = loadTexture("Texture/american_walnut_crown_cut_Normal.jpg", false);
	unsigned int wallD = loadTexture("Texture/Soi_RedBricks_Base_Color.jpg", true);
	unsigned int wallN = loadTexture("Texture/Soi_RedBricks_Normal.jpg", false);
	unsigned int bg0 = loadTexture("Texture/bg1.png", true);

	Shader g_buffer("Shader/G_Buffer.vs", "Shader/G_Buffer.fs");
	unsigned int gbufferMatrices = glGetUniformBlockIndex(g_buffer.ID, "Matrices");
	glUniformBlockBinding(g_buffer.ID, gbufferMatrices, 0);
	Shader singleColor("Shader/Unlit.vs", "Shader/Unlit.fs");
	unsigned int singleColorMatrices = glGetUniformBlockIndex(singleColor.ID, "Matrices");
	glUniformBlockBinding(singleColor.ID, singleColorMatrices, 0);
	Shader reflectShader("Shader/reflect.vs", "Shader/reflect.fs");
	unsigned int reflectShaderMatrices = glGetUniformBlockIndex(reflectShader.ID, "Matrices");
	glUniformBlockBinding(reflectShader.ID, reflectShaderMatrices, 0);
	Shader refractShader("Shader/refract.vs", "Shader/refract.fs");
	unsigned int refractShaderMatrices = glGetUniformBlockIndex(refractShader.ID, "Matrices");
	glUniformBlockBinding(refractShader.ID, refractShaderMatrices, 0);
	unsigned int uboMatrices;
	glGenBuffers(1, &uboMatrices);
	glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
	glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));

	Shader LightingPass("Shader/Vertex.vs", "Shader/LightingPass.fs");
	unsigned int gbufferDirLight = glGetUniformBlockIndex(LightingPass.ID, "DirLightInfo");
	glUniformBlockBinding(LightingPass.ID, gbufferDirLight, 1);
	unsigned int gbufferPointLight = glGetUniformBlockIndex(LightingPass.ID, "PointLightInfo");
	glUniformBlockBinding(LightingPass.ID, gbufferPointLight, 2);
	Shader skyboxShader("Shader/skybox.vs", "Shader/skybox.fs");
	Shader dirDepthShader("Shader/dir_shadow_mapping_depth.vs", "Shader/dir_shadow_mapping_depth.fs");
	Shader pointDepthShader("Shader/point_shadows_depth.vs", "Shader/point_shadows_depth.fs", "Shader/point_shadows_depth.gs");

	Shader HDRShader("Shader/Vertex.vs", "Shader/HDRColor.fs");
	Shader Gaussian_blur_hori("Shader/Vertex.vs", "Shader/Gaussian_blur_hori.fs");
	Shader Gaussian_blur_vert("Shader/Vertex.vs", "Shader/Gaussian_blur_vert.fs");
	Shader BloomShader("Shader/Vertex.vs", "Shader/Bloom.fs");
	Shader debugShader("Shader/Vertex.vs", "Shader/Fragment.fs");



	Light dirLight(LightType::direction);
	dirLight.position = vec3(5.0f, 7.0f, 5.0f);
	dirLight.direct = vec3(-1, -1.414f, -1);
	dirLight.intensity = 0.4f;
	dirLight.shadow_width = 1024;
	dirLight.shadow_height = 1024;
	dirLight.GetDirLightSpaceMatrix();
	dirLight.SetShaderUBO();

	Light pointLight(LightType::point);
	pointLight.position = vec3(2.0f, 1.5f, 0.0f);
	pointLight.diffuse = vec3(0.95f, 1.0f, 0.85f);
	pointLight.intensity = 1.0f;
	pointLight.shadow_width = 1024;
	pointLight.shadow_height = 1024;
	pointLight.SetShaderUBO();

	unsigned int gBuffer;
	glGenFramebuffers(1, &gBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
	unsigned int gPosition, gNormal, gAlbedoSpec;

	glGenTextures(1, &gPosition);
	glBindTexture(GL_TEXTURE_2D, gPosition);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gPosition, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
	glGenTextures(1, &gNormal);
	glBindTexture(GL_TEXTURE_2D, gNormal);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, gNormal, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
	glGenTextures(1, &gAlbedoSpec);
	glBindTexture(GL_TEXTURE_2D, gAlbedoSpec);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, gAlbedoSpec, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
	unsigned int attachments[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
	glDrawBuffers(3, attachments);

	unsigned int rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);


#pragma region  光照阴影


	unsigned int dirLightDepthMapFBO;
	glGenFramebuffers(1, &dirLightDepthMapFBO);
	// create depth texture
	unsigned int dirDepthMap;
	glGenTextures(1, &dirDepthMap);
	glBindTexture(GL_TEXTURE_2D, dirDepthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, dirLight.shadow_width, dirLight.shadow_height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	// attach depth texture as FBO's depth buffer
	glBindFramebuffer(GL_FRAMEBUFFER, dirLightDepthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, dirDepthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;

	unsigned int pointLightDepthMap;
	glGenFramebuffers(1, &pointLightDepthMap);
	unsigned int pointDepthCubemap;
	glGenTextures(1, &pointDepthCubemap);
	glBindTexture(GL_TEXTURE_CUBE_MAP, pointDepthCubemap);
	for (unsigned int i = 0; i < 6; ++i)
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, pointLight.shadow_width, pointLight.shadow_height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindFramebuffer(GL_FRAMEBUFFER, pointLightDepthMap);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, pointDepthCubemap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
#pragma endregion

#pragma region 后处理



	unsigned int lightingFBO;
	glGenFramebuffers(1, &lightingFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, lightingFBO);

	unsigned int sourceColorBuffer;
	glGenTextures(1, &sourceColorBuffer);
	glBindTexture(GL_TEXTURE_2D, sourceColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, sourceColorBuffer, 0);
	unsigned int sourceDepthBuffer;
	glGenRenderbuffers(1, &sourceDepthBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, sourceDepthBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, sourceDepthBuffer);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;


	unsigned int HDRFBO;
	glGenFramebuffers(1, &HDRFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, HDRFBO);
	unsigned int hdrSourceColorBuffer;
	glGenTextures(1, &hdrSourceColorBuffer);
	glBindTexture(GL_TEXTURE_2D, hdrSourceColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, hdrSourceColorBuffer, 0);
	unsigned int hdrColorBuffer;
	glGenTextures(1, &hdrColorBuffer);
	glBindTexture(GL_TEXTURE_2D, hdrColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, hdrColorBuffer, 0);
	unsigned int hdrAttachments[] = { GL_COLOR_ATTACHMENT0 ,GL_COLOR_ATTACHMENT1 };
	glDrawBuffers(2, hdrAttachments);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	unsigned int BloomFBO;
	glGenFramebuffers(1, &BloomFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, BloomFBO);

	unsigned int BloomColorBuffer;
	glGenTextures(1, &BloomColorBuffer);
	glBindTexture(GL_TEXTURE_2D, BloomColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, BloomColorBuffer, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	unsigned int BlurFBO_0;
	glGenFramebuffers(1, &BlurFBO_0);
	glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_0);
	unsigned int blurColorbuffer_0;
	glGenTextures(1, &blurColorbuffer_0);
	glBindTexture(GL_TEXTURE_2D, blurColorbuffer_0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, blurColorbuffer_0, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	unsigned int BlurFBO_1;
	glGenFramebuffers(1, &BlurFBO_1);
	glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_1);
	unsigned int blurColorbuffer_1;
	glGenTextures(1, &blurColorbuffer_1);
	glBindTexture(GL_TEXTURE_2D, blurColorbuffer_1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, blurColorbuffer_1, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		cout << "ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!" << endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

#pragma endregion
	//深度测试
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	////模板测试
	//glEnable(GL_STENCIL_TEST);
	//glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
	//glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	//剔除面
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//glFrontFace(GL_CCW); //逆时针（默认）
	//glFrontFace(GL_CW);//顺时针

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//线框模式

	//glEnable(GL_MULTISAMPLE);

	//glEnable(GL_FRAMEBUFFER_SRGB);
	//glDisable(GL_FRAMEBUFFER_SRGB);
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		vec3 oldD = pointLight.position - vec3(0, 1.5f, 0);
		glm::mat4 rotate(1.0);
		rotate = glm::rotate(rotate, radians(45.0f*deltaTime), vec3(0, 1, 0));
		glm::vec3 newD = (rotate)*vec4(oldD, 0);
		newD = newD + vec3(0, 1.5f, 0);
		pointLight.position = newD;
		pointLight.GetCubeShadowTransforms();
		pointLight.SetShaderUBO();


		glBindFramebuffer(GL_FRAMEBUFFER, dirLightDepthMapFBO);
		glViewport(0, 0, dirLight.shadow_width, dirLight.shadow_height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		dirDepthShader.use();
		dirDepthShader.setMat4("_dirLightSpaceMatrix", dirLight.GetDirLightSpaceMatrix());
		plane.Draw(dirDepthShader);
		cube1.Draw(dirDepthShader);
		cube2.Draw(dirDepthShader);
		cube3.Draw(dirDepthShader);
		cube4.Draw(dirDepthShader);

		glBindFramebuffer(GL_FRAMEBUFFER, pointLightDepthMap);
		glViewport(0, 0, pointLight.shadow_width, pointLight.shadow_height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		pointDepthShader.use();
		for (unsigned int i = 0; i < pointLight.cubeShadowTransforms.size(); ++i)
			pointDepthShader.setMat4("_shadowMatrices[" + std::to_string(i) + "]", pointLight.cubeShadowTransforms[i]);
		pointDepthShader.setFloat("_far_plane", pointLight.far_plane);
		pointDepthShader.setVec3("_lightPos", pointLight.position);
		plane.Draw(pointDepthShader);
		cube1.Draw(pointDepthShader);
		cube2.Draw(pointDepthShader);
		cube3.Draw(pointDepthShader);
		cube4.Draw(pointDepthShader);



		glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		g_buffer.use();
		g_buffer.setInt("_texture_diffuse1", 0);
		g_buffer.setInt("_texture_normal1", 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, woodD);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, woodN);
		plane.Draw(g_buffer);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, irregularD);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, irregularN);
		cube1.Draw(g_buffer);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, wallD);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, wallN);
		cube2.Draw(g_buffer);


		glBindFramebuffer(GL_FRAMEBUFFER, lightingFBO);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		LightingPass.use();
		LightingPass.setInt("_gPosition", 0);
		LightingPass.setInt("_gNormal", 1);
		LightingPass.setInt("_gAlbedoSpec", 2);
		LightingPass.setVec3("_viewPos", camera.Position);
		LightingPass.setInt("_dirDepthMap", 3);
		LightingPass.setInt("_pointDepthMap", 4);



		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, gPosition);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, gNormal);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, gAlbedoSpec);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, dirDepthMap);
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_CUBE_MAP, pointDepthCubemap);
		glDepthMask(GL_FALSE);
		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDepthMask(GL_TRUE);

		glBindFramebuffer(GL_READ_FRAMEBUFFER, gBuffer);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, lightingFBO);
		glBlitFramebuffer(0, 0, SCR_WIDTH, SCR_HEIGHT, 0, 0, SCR_WIDTH, SCR_HEIGHT, GL_DEPTH_BUFFER_BIT, GL_NEAREST);

		reflectShader.use();
		reflectShader.setVec3("cameraPos", camera.Position);
		reflectShader.setInt("skybox", 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, skybox.cubeMap);
		cube3.Draw(reflectShader);
		refractShader.use();
		refractShader.setVec3("cameraPos", camera.Position);
		refractShader.setInt("skybox", 0);
		cube4.Draw(reflectShader);

		singleColor.use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, whiteTex);
		singleColor.setVec3("_color", pointLight.diffuse*3.0f);
		lightCube.SetTransform(pointLight.position, vec3(0), vec3(0.1f));
		lightCube.Draw(singleColor);

		glCullFace(GL_FRONT);
		glDepthFunc(GL_LEQUAL);
		skyboxShader.use();
		skybox.DrawSkyBox(skyboxShader, camera, projection);
		glDepthFunc(GL_LESS);
		glCullFace(GL_BACK);






		glBindFramebuffer(GL_FRAMEBUFFER, HDRFBO);
		glClear(GL_COLOR_BUFFER_BIT);
		HDRShader.use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sourceColorBuffer);
		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);


		glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_0);
		glClear(GL_COLOR_BUFFER_BIT);
		Gaussian_blur_hori.use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, hdrColorBuffer);
		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		unsigned int amount = 10;
		for (unsigned int i = 0; i < amount; i++)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_1);
			Gaussian_blur_hori.use();
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, blurColorbuffer_0);  // bind texture of other framebufferMultiSampled (or scene if first iteration)
			glBindVertexArray(quadVAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);

			glBindFramebuffer(GL_FRAMEBUFFER, BlurFBO_0);
			Gaussian_blur_vert.use();
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, blurColorbuffer_1);  // bind texture of other framebufferMultiSampled (or scene if first iteration)
			glBindVertexArray(quadVAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);
		}

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		BloomShader.use();
		BloomShader.setInt("scene", 0);
		BloomShader.setInt("bloomBlur", 1);
		BloomShader.setFloat("exposure", 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sourceColorBuffer);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, blurColorbuffer_0);

		//debugShader.use();
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, );

		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}





unsigned int genQuad()
{
	// positions
	glm::vec3 pos1(-1.0f, 1.0f, 0.0f);
	glm::vec3 pos2(-1.0f, -1.0f, 0.0f);
	glm::vec3 pos3(1.0f, -1.0f, 0.0f);
	glm::vec3 pos4(1.0f, 1.0f, 0.0f);
	// texture coordinates
	glm::vec2 uv1(0.0f, 1.0f);
	glm::vec2 uv2(0.0f, 0.0f);
	glm::vec2 uv3(1.0f, 0.0f);
	glm::vec2 uv4(1.0f, 1.0f);
	// normal vector
	glm::vec3 nm(0.0f, 0.0f, 1.0f);

	// calculate tangent/bitangent vectors of both triangles
	glm::vec3 tangent1, bitangent1;
	glm::vec3 tangent2, bitangent2;
	// triangle 1
	// ----------
	glm::vec3 edge1 = pos2 - pos1;
	glm::vec3 edge2 = pos3 - pos1;
	glm::vec2 deltaUV1 = uv2 - uv1;
	glm::vec2 deltaUV2 = uv3 - uv1;

	float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1 = glm::normalize(tangent1);

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1 = glm::normalize(bitangent1);

	// triangle 2
	// ----------
	edge1 = pos3 - pos1;
	edge2 = pos4 - pos1;
	deltaUV1 = uv3 - uv1;
	deltaUV2 = uv4 - uv1;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent2 = glm::normalize(tangent2);


	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent2 = glm::normalize(bitangent2);


	float quadVertices[] = {
		// positions            // normal         // texcoords  // tangent                          // bitangent
		pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
		pos2.x, pos2.y, pos2.z, nm.x, nm.y, nm.z, uv2.x, uv2.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
		pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,

		pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
		pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
		pos4.x, pos4.y, pos4.z, nm.x, nm.y, nm.z, uv4.x, uv4.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z
	};
	// configure plane VAO
	unsigned int quadVAO, quadVBO;
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(11 * sizeof(float)));

	return quadVAO;
}