#pragma once
#include <iostream>

/*第一个是模板类型,第二个是值*/
/*标准库规定必须是整形 枚举 指针 引用 浮点数，不能是对象*/
template <typename T,/*const T DEFAULT=T()*/ const T& DEFAULT>
class ArrayList
{
public:
    using value_type = T;
    ArrayList(size_t i = 30) : mLen(i)
    {
        if (i > 0)
        {
            mPint = new T[mLen];
            for(size_t i = 0; i<mLen;i++)
            {
                mPint[i] = DEFAULT;
            }
        }
        else
        {
            mPint = nullptr;
        }
    }
    ~ArrayList()
    {
        delete[] mPint;
        mPint = nullptr;
    }
    void resize(int nLen)
    {
        delete[] mPint;
        //参数检查省略
        mLen = nLen;
        mPint = new T[mLen];
        for (size_t i = 0; i < mLen; i++)
        {
            mPint[i] = DEFAULT;
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
    T *mPint;
    size_t mLen;
};