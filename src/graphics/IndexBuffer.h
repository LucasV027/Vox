#pragma once

class IndexBuffer {
public:
    IndexBuffer();

    void Load(const unsigned int* data, unsigned int count);

    ~IndexBuffer();

    void Bind() const;

    void Unbind() const;

    unsigned int GetCount() const;

private:
    unsigned int id;
    unsigned int count;
};
