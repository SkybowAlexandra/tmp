#pragma once
#include <iostream>
#include <cstring>
#define NOT_FOUND_INDEX ((size_t)-1)

/*============================================================模板函数的部分特例化========================================*/
template <typename T>
size_t Find( T const&value,  T const *pArray, size_t &&nArrLen)
{
    std::cout << "template " << std::endl;
    for (size_t i = 0; i < nArrLen; i++)
    {
        if (value == pArray[i])
        {
            return i;
        }
    }
    return NOT_FOUND_INDEX;
}
/*C++标准不允许函数的模板部分特例化*/
#if 0
template <typename T>
size_t Find<T *>(T *const &value, T *const *pArray, size_t nArrLen)
{
    for (size_t i = 0; i < nArrLen; i++)
    {
        if (*value == *pArray[i])
        {
            return i;
        }
    }
    return NOT_FOUND_INDEX;
}
#endif
/*为T 指针重载*/
template <typename T>
size_t Find(T *const &value, T *const *pArray, size_t &&nArrLen)
{
    std::cout << "T指针 重载版本 " << std::endl;
    for (size_t i = 0; i < nArrLen; i++)
    {
        if (*value == *pArray[i])
        {
            return i;
        }
    }
    return NOT_FOUND_INDEX;
}
/*使用完全特例化重载函数const char *版本*/
template <>
size_t Find<const char *>( const char * const &value,  const char *const*pArray, size_t &&nArrLen)
{
    std::cout << "const char * 重载版本" << std::endl;
    for (size_t i = 0; i < nArrLen; i++)
    {
#if __linux__
        if (strcasecmp(value, pArray[i]) == 0)
#elif _WIN32
        if (stricmp(*value, *pArray[i]) == 0)
#endif
        {
            return i;
        }
    }
    return NOT_FOUND_INDEX;
}

/*在所有的重载版本中,函数模板特例化和特定模板实例化中 编译器 总是选择 "最具体的"函数版本
非模板函数 > 完全特例化的函数(必须显式调用) > 部分特例化的函数 > 模板函数
*/
#if 0
size_t Find( const char * &value,  const char **pArray, size_t &&nArrLen)
{
    std::cout << "函数版本" << std::endl;
    for (size_t i = 0; i < nArrLen; i++)
    {
#if __linux__
        if (strcasecmp(value, pArray[i]) == 0)
#elif _WIN32
        if (stricmp(*value, *pArray[i]) == 0)
#endif
        {
            return i;
        }
    }
    return NOT_FOUND_INDEX;
}
#endif

/*51.03*/