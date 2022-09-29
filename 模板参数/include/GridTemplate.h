#pragma once
#include <vector>
#include <optional>
#include <memory_resource>
template <typename T, 
    template<class E,class _Alloc = std::allocator<E>> class Container = std::vector>
class GridTemplate
{
public:
    /*explicit 取消构造函数自动隐式转换*/
    explicit GridTemplate(size_t nWidth = kDefaultWidth, size_t nHeight = kDefaultHeight)
    :mWidth(nWidth), mHeight(nHeight)
    {
        mCells.resize(mWidth);
        for(size_t i = 0; i< mCells.size(); i++)
        {
            mCells[i].resize(mHeight);
        }
    }
    typename T& at(size_t x,size_t y);

    static const size_t kDefaultWidth = 30;
    static const size_t kDefaultHeight = 30;
private:
    std::vector<Container<T>> mCells;
    size_t mWidth = 0, mHeight = 0;
};

template <typename T, template<class E,class _Alloc = std::allocator<E>> class Container>
T& GridTemplate<T,Container>::at(size_t x ,size_t y)
{
    return mCells[x][y];
}