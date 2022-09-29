#include <iostream>

template<bool _test,typename T>
struct TEnableIF{};


template<typename T>
struct TEnableIF<true,T>
{
    using type =T;
};

int main()
{
    TEnableIF<true,int>::type a = 123;
    return 0;
}

