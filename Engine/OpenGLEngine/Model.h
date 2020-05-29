#ifndef MODEL_H
#define MODEL_H

using namespace std;

class Model {
public:
    /*  Model Data */
    vector<MeshTexture> textures_loaded;
    vector<Mesh> meshes;
    string directory;
    bool gammaCorrection;

	Model(const char* path);
	void Draw(Shader shader);

private:
	unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);
    /*  º¯Êý   */
	void loadModel(string path);

	void processNode(aiNode* node, const aiScene* scene);

	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

	vector<MeshTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

};
#endif