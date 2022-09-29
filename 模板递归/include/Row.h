/*模板递归*/
#pragma once
#include <vector>
#include <iostream>
#include <array>
//第二个参数代表维度
template <typename T,size_t N>
class Row
{
public:
    explicit Row(size_t nInitSize = 30) //构造函数默认30
    {
        this->resize(nInitSize);
    }
    Row<T,N-1> &operator[](size_t nIndex)
    {
        return this->mElements[nIndex]; //重载[] 只读版本
    }

    const Row<T,N-1> &operator[](size_t nIndex) const //重载[] 只读版本
    {
        return this->mElements[nIndex];
    }
    void resize(size_t newSize) //设置大小
    {
        this->mElements.resize(newSize);
        for(auto it : this->mElements) //填充
        {
            this->mElements.resize(newSize);
        }
    }
    size_t size() const
    {
        return this->mElements.size();
    }
protected:
    std::vector<Row<T,N-1>> mElements;
};



template <typename T>
class Row<T,1>
{
public:
    explicit Row(size_t nInitSize = 30) //构造函数默认30
    {
        this->resize(nInitSize);
    }
    T &operator[](size_t nIndex)
    {
        return this->mElements[nIndex]; //重载[] 只读版本
    }
    const T &operator[](size_t nIndex) const //重载[] 只读版本
    {
        return this->mElements[nIndex];
    }
    void resize(size_t newSize) //设置大小
    {
        this->mElements.resize(newSize);
    }
    size_t size() const
    {
        return this->mElements.size();
    }
protected:
    std::vector<T> mElements;
};