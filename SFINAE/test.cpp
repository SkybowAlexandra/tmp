/********************************************************************************
 * @文件名:
 * @作者: 赵
 * @版本: 1.0
 * @时间: 2021-
 * @格式:
 * @说明:替换失败不报错的方法就叫SFINAE
 ********************************************************************************/
#include <iostream>
#include <vector>

/*不会主动去选择可变参数这个重载*/
class CMyClass
{
public:
    using size_type = unsigned int;
};


//数组特例
template <typename T, unsigned N>
std::size_t len(T (&)[N])
{
    return N;
}
//容器特例
template <typename T>
decltype(T().size(), typename T::size_type()) len(T const &t) //逗号运算符只以右边的表达式为准
{
    return t.size();
}

unsigned len(...)
{
    return 0;
}

int main(int argc, char *argv[])
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //数组特例
    std::cout << len(a) << std::endl;
    
    std::vector<int> Myector{1, 2, 3, 4, 5}; //容器特例
    std::cout << len(Myector) << std::endl;
    std::cout << len(3.14) << std::endl;
    std::cout << len(CMyClass()) << std::endl;
    return 0;
}