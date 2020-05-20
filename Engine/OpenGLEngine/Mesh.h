#ifndef MESH_H
#define MESH_H

using namespace std;

struct Vertex {
public:
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};

struct Texture {
public:
    unsigned int id;
    string type;
    string path;
};

class Mesh {
public:
    /*  ��������  */
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;
    /*  ����  */
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader shader);
  
private:
    /*  ��Ⱦ����  */
    unsigned int VBO, EBO;
    /*  ����  */
	void setupMesh();
};
#endif