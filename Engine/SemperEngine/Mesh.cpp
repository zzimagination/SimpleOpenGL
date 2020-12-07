#include "Mesh.h"
#include "ResourceObjectCenter.h"

namespace SemperEngine
{
    using namespace Core;

    Mesh::Mesh()
    {
        object = ResourceObjectCenter::CreateCube();
    }

    Mesh::~Mesh()
    {
        ResourceObjectCenter::DeleteCube(object);
    }
    Mesh* Mesh::Copy()
    {
        auto obj = ResourceObjectCenter::CopyMesh(this->object);
        auto copy = new Mesh();
        ResourceObjectCenter::DeleteCube(copy->object);
        copy->object = obj;
        return copy;
    }
}