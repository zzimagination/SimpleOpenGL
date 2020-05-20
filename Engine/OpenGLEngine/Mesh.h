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
    /*  网格数据  */
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;
    /*  函数  */
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader shader);
  
private:
    /*  渲染数据  */
    unsigned int VBO, EBO;
    /*  函数  */
	void setupMesh();
};
#endif