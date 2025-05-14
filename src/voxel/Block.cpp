#include "Block.h"

Block::Block() : active(true), blockType(BlockType::Dirt) {}

Block::Block(const BlockType type) : active(true), blockType(type) {}

bool Block::IsActive() const { return active; }

void Block::SetActive(const bool active) { this->active = active; }
