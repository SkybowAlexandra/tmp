#pragma once
#include <iostream>

class IntArrayList
{
public:
    using value_type = int;
    IntArrayList(size_t i = 30) : mLen(i)
    {
        if (i > 0)
        {
            mPint = new int[mLen];
            for(size_t i = 0; i<mLen;i++)
            {
                mPint[i] = 2;
            }
        }
        else
        {
            mPint = nullptr;
        }
    }
    ~IntArrayList()
    {
        delete[] mPint;
        mPint = nullptr;
    }
    void resize(int nLen)
    {
        delete[] mPint;
        //参数检查省略
        mLen = nLen;
        mPint = new int[mLen];
        for (size_t i = 0; i < mLen; i++)
        {
            mPint[i] = 4;
        }
    }
    value_type &operator[](size_t i)
    {
        return mPint[i];
    }
    size_t size()
    {
        return mLen;
    }

private:
    int *mPint;
    size_t mLen;
};