#ifndef ENGINEDEF
#define ENGINEDEF

#define OPENGL

#define GLFW

#ifndef GLFW
#define WIN32_WIN
#endif // !GLFW



namespace SemperEngine {

	enum Vsync {
		vsync,
		helf,
	};

	constexpr int Window_Width = 1920;

	constexpr int Window_Height = 1080;

	constexpr Vsync project_vsync = vsync;
}

#endif // !ENGINEDEF