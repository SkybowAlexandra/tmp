#pragma once
#include <vector>
#include <optional>
template <typename T, typename Container = std::vector<std::optional<T>>>
class Grid
{
public:
    /*explicit 取消构造函数自动隐式转换*/
    explicit Grid(size_t nWidth = kDefaultWidth, size_t nHeight = kDefaultHeight)
    :mWidth(nWidth), mHeight(nHeight)
    {
        mCells.resize(mWidth);
        for(size_t i = 0; i< mCells.size(); i++)
        {
            mCells[i].resize(mHeight);
        }
    }
    typename Container::value_type &at(size_t x,size_t y); //typename告诉编译器Container它是一种类型

    static const size_t kDefaultWidth = 30;
    static const size_t kDefaultHeight = 30;
private:
    std::vector<Container> mCells;
    size_t mWidth = 0, mHeight = 0;
};

template <typename T, typename Container>
inline typename Container::value_type & Grid<T,Container>::at(size_t x ,size_t y)
{
    return mCells[x][y];
}