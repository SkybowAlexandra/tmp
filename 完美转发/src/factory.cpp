/********************************************************************************
 * @文件名:
 * @作者: 赵
 * @版本: 1.0
 * @时间: 2021-
 * @格式:
 * @说明:
 ********************************************************************************/
#include <iostream>
#include <memory>

class CTemp
{
    int m_iData;

public:
    CTemp(int &arg)  noexcept : m_iData(arg)
    {
        std::cout << "CTemp(int &arg) " << std::endl;
    }
    CTemp(int &&arg)  noexcept : m_iData(arg)
    {
        std::cout << "CTemp(int &&arg) " << std::endl;
    }
};

template <typename T, typename Arg>
std::shared_ptr<T> factory(Arg &&arg)
{
    return std::shared_ptr<T>(new T(std::forward<Arg>(arg)));
}

int main(int argc, char *argv[])
{
    auto p1 = factory<CTemp>(5);

    int value = 5;
    auto p2 = factory<CTemp>(value);

    return 0;
}