#pragma once
#include <vector>
#include <string>
#include "TextureType.h"

using namespace std;

class Texture
{
public:

	int width;

	int height;

	int channels;

	unsigned char* data;

	Texture();

	~Texture();

	void LoadFile(string path);

private:

	

};

