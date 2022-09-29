/********************************************************************************
 * @文件名:
 * @作者: 赵
 * @版本: 1.0
 * @时间: 2022-
 * @格式:
 * @说明: 计算乘阶
 ********************************************************************************/
#include <iostream>
template <int N>
constexpr int factorial = N *factorial<N - 1>;

template <>
constexpr int factorial<0> = 1;

int main()
{
    std::cout << factorial<5> << std::endl;
    return 0;
}
