#include "bit_set.h"

template <class T>
bitSet<T>::bitSet(int sz) : setSize(sz)
{
    assert(setSize > 0);
    vectorSize = (setSize + 15) >> 4;
    bitVector = new int[vectorSize];
    assert(bitVector != NULL);
    for (int i = 0; i < vectorSize; i++)
    {
        bitVector[i] = 0;
    }
};

template <class T>
bitSet<T>::bitSet(const bitSet<T> &R)
{
    setSize = R.setSize;
    vectorSize = R.vectorSize;
    bitVector = new int[vectorSize];
    assert(bitVector != NULL);
    for (int i = 0; i < vectorSize; i++)
    {
        bitVector[i] = R.bitVector[i];
    }
};

template <class T>
int bitSet<T>::GetMember(const T x)
{
    int ad = x / 16, id = x % 16;
    unsigned short elem = bitVector[ad];
    return ((elem >> (15 - id)) & 1);
};

template <class T>
void bitSet<T>::PutMember(const T x, int v)
{
    int ad = x / 16, id = x % 16;
    unsigned short elem = bitVector[ad];
    unsigned short temp = elem >> (15 - id);
    elem = elem << (id + 1);
    if (temp % 2 == 0 && v == 1)
    {
        temp = temp + 1;
    }
    else if (temp % 2 == 1 && v == 0)
    {
        temp = temp - 1;
    }
    bitVector[ad] = (temp << (15 - id)) | (elem >> (id + 1));
};

template <class T>
bool bitSet<T>::AddMember(const T x)
{
    assert(x >= 0 && x < setSize);
    if (getMember(x) == 0)
    {
        putMember(x, 1);
        return true;
    }
    return false;
};

template <class T>
bool bitSet<T>::DelMember(const T x)
{
    assert(x >= 0 && x < setSize);
    if (getMember(x) == 1)
    {
        putMember(x, 0);
        return true;
    }
    return false;
};

template <class T>
bitSet<T> bitSet<T>::operator+(const bitSet<T> &R)
{
    assert(vectorSize == R.vectorSize);
    set temp(setSize);
    for (int i = 0; i < vectorSize; i++)
    {
        temp.bitVector[i] = bitVector[i] | R.bitVector[i];
    }
    return temp;
};

template <class T>
bitSet<T> bitSet<T>::operator*(const bitSet<T> &R)
{
    assert(vectorSize == R.vectorSize);
    set temp(setSize);
    for (int i = 0; i < vectorSize; i++)
    {
        temp.bitVector[i] = bitVector[i] & R.bitVector[i];
    }
    return temp;
};

template <class T>
bitSet<T> bitSet<T>::operator-(const bitSet<T> &R)
{
    assert(vectorSize == R.vectorSize);
    set temp(setSize);
    for (int i = 0; i < vectorSize; i++)
    {
        temp.bitVector[i] = bitVector[i] & !R.bitVector[i];
    }
    return temp;
};

template <class T>
bool bitSet<T>::Contains(const T x)
{
    assert(x >= 0 && x <= setSize);
    return (getMember(x) == 1) ? true : false;
};

template <class T>
bool bitSet<T>::SubSet(bitSet<T> &R)
{
    assert(setSize == R.setSize);
    for (int i = 0; i < vectorSize; i++)
    {
        if (bitVector[i] & !R.bitVector[i])
        {
            return false;
        }
    }
    return true;
};

template <class T>
bool bitSet<T>::operator==(bitSet<T> &R)
{
    if (vectorSize != R.vectorSize)
    {
        return false;
    }
    for (int i = 0; i < vectorSize; i++)
    {
        if (bitVector[i] != R.bitVector[i])
        {
            return false;
        }
    }
    return true;
};