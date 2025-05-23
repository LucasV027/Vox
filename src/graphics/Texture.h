#pragma once

#include <filesystem>
#include <vector>

class Texture {
public:
    Texture();

    ~Texture();

    void Load(const std::filesystem::path& filepath);

    void LoadCubeMap(const std::vector<std::filesystem::path>& faces);

    void Bind(unsigned int slot = 0) const;

    void Unbind();

private:
    unsigned int id;
    unsigned int type;
};
