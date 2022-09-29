/********************************************************************************
 * @文件名:
 * @作者: 赵
 * @版本: 1.0
 * @时间: 2021-
 * @格式:
 * @说明:
 ********************************************************************************/
#include <iostream>
#include <optional>
#include <cmath>

std::optional<float> mysqrt(float x)
{
    if (x >= 0.f)
    {
        return std::sqrt(x);
    }
    else
    {
        return std::nullopt;
    }
}

int main(int argc, char *argv[])
{
    auto ret = mysqrt(3.f);
    if (ret.has_value())

        std::cout << "成功 ! 结果为 :\n"
                  << ret.value() << std::endl;
    else
        std::cout << "失败,找不到平方根" << std::endl;
    return 0;
}
