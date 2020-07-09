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

	string path;

	TexType textureType;

	unsigned char* data;

	Texture();

	~Texture();

	void LoadTexture(string path);

private:

	

};

