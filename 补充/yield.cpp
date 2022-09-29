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
#include <type_traits>
template <typename Func>
void fetch_data(Func const &func)
{
    for(int i =0;i<32;i++)
    {
        func(i);
        func(i+0.5f);
    }
}


int main(int argc,char *argv[])
{
    std::vector<int> res_i;
    std::vector<float> res_f;
    fetch_data
    (
        [&] (auto const &x)
        {
            using T = std::decay_t<decltype(x)>;
            if constexpr (std::is_same_v<T,int>)
            {
                res_i.push_back(x);

            } 
            else if constexpr (std::is_same_v<T,float>)
            {
                res_f.push_back(x);
            }
        }
    );
    for(auto it : res_i)
    std::cout << "res_i: " << it << std::endl;
    for(auto it : res_f)
    std::cout << "res_f: " << it << std::endl;

    return 0;
}

