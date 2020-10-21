#include "Mesh.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
    using namespace Core;

    Mesh::Mesh()
    {
        _package = ResourcePackage<VertexData>(new VertexData());
        _package.GetResource()->Package(_package);
        _package.Use(this);
    }

    Mesh::Mesh(ResourcePackage<VertexData> package)
    {
        _package = package;
        _package.Use(this);
    }

    Mesh::~Mesh()
    {
        _package.Dispose(this);
    }
    Core::ResourcePackage<Core::VertexData> Mesh::Package()
    {
        return _package;
    }
}