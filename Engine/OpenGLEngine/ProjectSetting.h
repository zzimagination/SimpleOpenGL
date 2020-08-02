#ifndef PROJECT_SETTING
#define PROJECT_SETTING

class GameWindow;

class ProjectSetting
{
public:

	static int GetWindowWidth();

	static int GetWindowHeight();

private:

	static int windowWidth;

	static int windowHeight;

	friend GameWindow;
};
#endif // !PROJECT_SETTING





