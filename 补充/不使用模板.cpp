/********************************************************************************
 * @文件名:
 * @作者: 赵
 * @版本: 1.0
 * @时间: 2021-
 * @格式:
 * @说明:lambda 避免模板参数
 ********************************************************************************/
#include <iostream>
#include <functional>

void call_twice(std::function<int(int)> const &func)
{
    std::cout << func(0) << std::endl;
    std::cout << func(1) << std::endl;
    std::cout << "Func大小: " << sizeof(func) << std::endl;
}

std::function<int(int)> make_twice(int fac)
{
    return [=](int n)
    { return n * fac; };
}

int main(int argc, char *argv[])
{
    auto twice = make_twice(2);
    call_twice(twice);
    return 0;
}
