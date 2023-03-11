
class ArrayBuffer
{
private:
    char *data; // container for data (the buffer)
    int index;  // next place in the data we write to (also how full it is)
public:
    ArrayBuffer();
    template <typename T>
    ArrayBuffer(const T &);
    void push_back(const char &);  // add binary val into data (as char, 1 byte)
    void push_back(const int &);   // add binary vals into data (as int, 4 bytes)
    void push_back(const float &); // add binary val into data (as float, 4 bytes, iee754)
    template <typename T>
    void set(const T &);   // set binary val into data (as T, sizeof(T) bytes)
    char *getData() const; // return ptr to the data (first byte)
    int getSize() const;   // return index (used to determine size)
    void clear();          // reset index to 0
};