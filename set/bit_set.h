//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_BIT_SET_H
#define CYBER_DASH_BIT_SET_H

#include <assert.h>
#include <iostream>
// enum bool {false,true};
const int DefaultSize = 50;
template <typename T>
class bitSet
{
public:
    bitSet(int sz = DefaultSize);
    bitSet(const bitSet<T> &R);
    ~bitSet() { delete[] bitVector; };
    void MakeEmpty()
    {
        for (int i = 0; i < vectorSize; i++)
        {
            bitVector[i] = 0;
        }
    }
    int GetMember(const T x);
    void PutMember(const T x, int v);
    bool AddMember(const T x);
    bool DelMember(const T x);
    bitSet<T> &operator = (const bitSet<T> &R);
    bitSet<T> operator + (const bitSet<T> &R);
    bitSet<T> operator *(const bitSet<T> &R);
    bitSet<T> operator - (const bitSet<T> &R);
    bool Contains(const T x);
    bool SubSet(bitSet<T> &R);
    bool operator==(bitSet<T> &R);
    friend istream &operator>>(istream &in, bitSet<T> &R);
    friend ostream &operator<<(ostream &out, bitSet<T> &R);

private:
    int setSize;
    int vectorSize;
    unsigned short *bitVector;
};
#endif // CYBER_DASH_BIT_SET_H
