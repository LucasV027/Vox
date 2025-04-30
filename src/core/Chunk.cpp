#include "Chunk.h"

Chunk::Chunk() : position({0, 0, 0}) {}

void Chunk::Update(const double deltaTime) {}


void Chunk::Render(const Renderer& renderer, const Program& program) {
    std::vector<glm::vec3> vertices;
    std::vector<unsigned int> indices;

    for (int i = 0; i < CHUNK_TOTAL_SIZE; i++) {
        if (blocks[i].IsActive()) {
            AddCube(IndexTo3D(i), vertices, indices);
        }
    }

    VertexArray vao;
    vao.Init();

    VertexBuffer vbo;
    vbo.Load(vertices.data(), vertices.size() * sizeof(glm::vec3));

    VertexBufferLayout vboLayout;
    vboLayout.Push<float>(3);

    vao.AddBuffer(vbo, vboLayout);

    IndexBuffer ibo;
    ibo.Load(indices.data(), indices.size());

    renderer.Draw(vao, ibo, program);
}


void Chunk::AddCube(const glm::vec3& position, std::vector<glm::vec3>& vertices,
                    std::vector<unsigned int>& indices) {
    // Cube unit size
    float s = 1.0f;

    // Base vertex positions (local to (0,0,0))
    std::vector<glm::vec3> cubeVertices = {
        {0, 0, 0}, {s, 0, 0}, {s, s, 0}, {0, s, 0}, // Back face
        {0, 0, s}, {s, 0, s}, {s, s, s}, {0, s, s}  // Front face
    };

    // Offset vertices by position and add to the vertices vector
    const auto baseIndex = static_cast<unsigned int>(vertices.size());
    for (const auto& v : cubeVertices) {
        vertices.push_back(v + position);
    }

    // Each face is made of 2 triangles (6 indices per face)
    std::vector<unsigned int> cubeIndices = {// Back face
                                             0, 1, 2, 2, 3, 0,
                                             // Front face
                                             4, 5, 6, 6, 7, 4,
                                             // Left face
                                             0, 4, 7, 7, 3, 0,
                                             // Right face
                                             1, 5, 6, 6, 2, 1,
                                             // Bottom face
                                             0, 1, 5, 5, 4, 0,
                                             // Top face
                                             3, 2, 6, 6, 7, 3};

    // Add indices with offset
    for (const unsigned int idx : cubeIndices) {
        indices.push_back(baseIndex + idx);
    }
}

glm::ivec3 Chunk::IndexTo3D(int i) {
    return {i % CHUNK_SIZE, (i / CHUNK_SIZE) % CHUNK_SIZE, i / (CHUNK_SIZE * CHUNK_SIZE)};
}
