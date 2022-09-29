/********************************************************************************
* @文件名:
* @作者: 赵
* @版本: 1.0
* @时间: 2021-
* @格式: 
* @说明: 
********************************************************************************/
#include <iostream>
void print_double(double n)
{
    std::cout << "double " << n << std::endl;
}

void print_int(int n)
{
    std::cout << "int " << n << std::endl;
}
template<typename Func>
void call_twice(Func const&func)
{
    func(0);
    func(1.2);
}

int main(int argc,char *argv[])
{
    call_twice(print_int);
    call_twice(print_double);
    call_twice([](int n ){std::cout << "lambada " << n << std::endl;});
    return 0;
}

