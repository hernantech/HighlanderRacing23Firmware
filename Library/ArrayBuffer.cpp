#include "ArrayBuffer.h"

ArrayBuffer::ArrayBuffer()
{
    data = new char[8];
}

template <typename T>
ArrayBuffer::ArrayBuffer(const T &t)
{
    data = new char[8];
    set(t);
}

void ArrayBuffer::push_back(const char &c)
{
    if (index < 8)
    {
        data[index] = c;
        index++;
    }
}

void ArrayBuffer::push_back(const int &i)
{
    if (index < 4)
    {
        data[index] = (i >> 24) & 0xFF;
        data[index + 1] = (i >> 16) & 0xFF;
        data[index + 2] = (i >> 8) & 0xFF;
        data[index + 3] = i & 0xFF;
    }
}

void ArrayBuffer::push_back(const float &f)
{
    if (index < 4)
    {
        char *message_ptr = (char *)&f;
        for (int i = 0; i < 4; i++)
        {
            data[index + i] = message_ptr[i];
        }
    }
}

char *ArrayBuffer::getData() const
{
    return data;
}

int ArrayBuffer::getSize() const
{
    return index;
}

void ArrayBuffer::clear()
{
    index = 0;
}

template <typename T>
void ArrayBuffer::set(const T &)
{
    clear();
    push_back(T);
}
