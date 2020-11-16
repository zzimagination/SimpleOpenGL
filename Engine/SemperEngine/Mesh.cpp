#include "Mesh.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
    using namespace Core;

    Mesh::Mesh()
    {
        _package = ResourcePackage<VertexData>(new VertexData());
        _package.Use();
    }

    Mesh::Mesh(ResourcePackage<VertexData> package)
    {
        _package = package;
        _package.Use();
    }

    Mesh::~Mesh()
    {
        _package.Dispose();
    }
    Core::ResourcePackage<Core::VertexData> Mesh::Package()
    {
        return _package;
    }
}