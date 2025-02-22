#pragma once

#include <stddef.h> // for size_t
#include <string>   // for basic_string, string
#include <vector>   // for vector
#include "Eigen.h"  // Eigen

class SimpleMesh;

class DataLoader
{
public:
    size_t size();
    std::string getName(size_t index);

    virtual bool createMeshes(size_t index,
                              SimpleMesh &sourceMesh,
                              SimpleMesh &targetMesh,
                              Matrix4f &gt_trans,
                              std::string sampling,
                              float samplingRatio) = 0;
    virtual void loadMeshPaths(const std::string &directoryPath) = 0;
    virtual ~DataLoader() = default;

protected:
    std::vector<std::string> meshPaths;
};

class MeshDataLoader : public DataLoader
{
public:
    bool createMeshes(size_t index,
                      SimpleMesh &sourceMesh,
                      SimpleMesh &targetMesh,
                      Matrix4f &gt_trans,
                      std::string sampling,
                      float samplingRatio);
    void loadMeshPaths(const std::string &directoryPath);
};

class PartialMeshDataLoader : public DataLoader
{
public:
    bool createMeshes(size_t index,
                      SimpleMesh &sourceMesh,
                      SimpleMesh &targetMesh,
                      Matrix4f &gt_trans,
                      std::string sampling,
                      float samplingRatio);
    void loadMeshPaths(const std::string &directoryPath);
};