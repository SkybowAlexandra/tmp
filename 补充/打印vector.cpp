/********************************************************************************
 * @文件名:
 * @作者: 赵
 * @版本: 1.0
 * @时间: 2021-
 * @格式:
 * @说明:
 ********************************************************************************/
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &a)
{
    size_t &&i = 0;
    os << "{";
    for (auto &&it : a)
    {
        i++;
        os << it;
        if (i != a.size())
            std::cout << ",";
    }
    os << "}";
    return os;
}

int main(int argc, char *argv[])
{

    std::vector<int> a = {1, 5, 8, 6, 7, 5, 0};
    std::cout << a << std::endl;
    std::vector<double> b = {3.14,2.17,45.4};
    std::cout << b << std::endl;

    return 0;
}
