#pragma once
#include <iostream>
#include <optional>
#include <string>

// std::optional<>为任意类型的可空实例建模

template <typename T, size_t WIDTH, size_t HEIGHT> //第一个类型参数,第二,第三非类型参数
class Grid
{
public:
    std::optional<T> at(size_t x, size_t y);
    Grid();
private:
    std::optional<T> mCells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
Grid<T,WIDTH,HEIGHT>::Grid()
{
    for (size_t i = 0; i < WIDTH; i++)
        for (size_t j = 0; j < HEIGHT; j++)
            this->mCells[i][j] = 0;
}
template <typename T, size_t WIDTH, size_t HEIGHT>
inline std::optional<T> Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
    return std::move(std::optional<T>(this->mCells[x][y]));
}

//=============================================部分特例化/*=============================================
template <size_t WIDTH, size_t HEIGHT>
class Grid<std::string, WIDTH, HEIGHT>
{
public:
    std::optional<std::string> at(size_t x, size_t y);

private:
    std::optional<std::string> mCells[WIDTH][HEIGHT];
};
template <size_t WIDTH, size_t HEIGHT>
inline std::optional<std::string> Grid<std::string, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
    // std::cout << x << " " << y << std::endl;
    return std::string("ABC");
}

//=============================================为指针特例化============================================
template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid<T *, WIDTH, HEIGHT>
{
public:
    Grid()
    {
        for (size_t i = 0; i < WIDTH; i++)
        {
            for (size_t j = 0; i < HEIGHT; i++)
            {
                mCells[i][j] = new T(4); // new int(4) ,指向一个4的数字
            }
        }
    }
    ~Grid()
    {
        for (size_t i = 0; i < WIDTH; i++)
        {
            for (size_t j = 0; i < HEIGHT; i++)
            {
                delete mCells[i][j].value();
                mCells[i][j] = nullptr;
            }
        }
    }
    std::optional<T *> at(size_t x, size_t y);

private:
    std::optional<T *> mCells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
inline std::optional<T *> Grid<T *, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
    return mCells[x][y];
}

//=============================================面向对象的实例化/*=============================================
class AbsClass
{
public:
    virtual void func1() = 0;
    virtual void func2() = 0;
};
class PartImpClass : public AbsClass
{
public:
    virtual void func1()
    {
    }
    virtual void func2() = 0; //还是有纯虚函数,无法实例化
};
class FullClass : public PartImpClass
{
public:
    virtual void func1()
    {
        std::cout << "我是func1,继承自PartImpClass类" << std::endl;
    }
    virtual void func2()
    {
        std::cout << "我是func2,继承自PartImpClass类" << std::endl;
    }
};