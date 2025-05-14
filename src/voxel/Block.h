#pragma once

enum class BlockType {
    Grass = 0,
    Dirt,
    Water,
    Stone,
    Wood,
    Sand,
};

class Block {
public:
    Block();
    explicit Block(BlockType type);
    ~Block() = default;

    bool IsActive() const;
    void SetActive(bool active);

    static constexpr int BLOCK_RENDER_SIZE = 2;

private:
    bool active;
    BlockType blockType;
};
