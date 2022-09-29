#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <tuple>

template <typename T>
void handleValue(T arg)
{
    std::cout << arg << std::endl;
}
template <>
void handleValue<int>(int arg)
{
    std::cout << "int: " << arg << std::endl;
}
template <>
void handleValue<const char *>(const char *arg)
{
    std::cout << "const char * : " << arg << std::endl;
}
template <>
void handleValue<double>(double arg)
{
    std::cout << "double: " << arg << std::endl;
}

#if 0
template <>
void handleValue<std::string>(std::string arg) //这里是值传递,如果需要传引用需要用到转发引用(forwarding references)的概念
{
    std::cout << "std::string: " << arg << std::endl;
}
#endif
void handleValue(std::string &&arg) //这里是值传递,如果需要传引用需要用到转发引用(forwarding references)的概念
{
    std::cout << "R std::string: " << arg << std::endl;
}

/*无参版本作为 模板递归退出条件*/
void processValues()
{
}
/* #if 0
template <typename T, typename... ArgTypes>
void processValues(T arg1, ArgTypes... args)
{
    handleValue(arg1);
    processValues(args...);
}
#endif */
//使用完美转发,如果传的是右值，就可以作为右值，如果是左值，可以作为左值转发

template <typename T1, typename... ArgTypes>
void processValues(T1 &&arg1, ArgTypes &&...args)
{
    std::cout << "args: " << sizeof...(args) << std::endl;
    handleValue(std::forward<T1>(arg1)); //处理参数,对不同类型进行了特例化
    processValues(std::forward<ArgTypes>(args) ...);
}
class ReadInterface
{
public:
    ReadInterface()
    {
        std::cout << "ReadInterface" << std::endl;
    }
    void Read()
    {
        std::cout << "Read: " << std::endl;
    }
};

class WriteInterface
{
public:
    void Write()
    {
        std::cout << "Write: " << std::endl;
    }
};
class PrintInterface
{
public:
    void Print()
    {
        std::cout << "print: " << std::endl;
    }
};
class ZipInterface
{
public:
    void Print()
    {
        std::cout << "ZipInterface: " << std::endl;
    }
};
/*可读 可写 可打印 可压缩,这样太麻烦 C++引入了混入模式*/
/* class MyInterface : public ReadInterface,public WriteInterface,public PrintInterface,public ZipInterface
{
}; */
template <typename... Mixins>
class MyInterface : public Mixins...
{
public:
    // MyInterface(const Mixins& ... Mixins): Mixins(Mixins) ... {}
};

/*折叠表达式*/
/* template <typename... Tn>
void processValues(const Tn &...args)
{
    (handleValue(args), ...); //,折叠
} */
template <typename... Tn>
void printValues(const Tn &...values)
{
    ((std::cout << values << " "), ...); // 逗号折叠
}
template <typename T, typename... Values>
double RightFolderSumOfValue(const T &init, Values... values)
{
    return (values + ... + init);
}
template <typename T, typename... Values>
double leftFolderSumOfValue(const T &init, Values... values)
{
    return (init + ... + values);
}
//计算乘阶
template <unsigned int N>
class Factorial
{
public:
    static constexpr __uint64_t value = N * Factorial<N - 1>::value;
};

template <>
class Factorial<0>
{
public:
    static constexpr __uint64_t value = 1;
};

constexpr uint64_t factorial(size_t N)
{
    if (N == 0)
        return 1;
    else
        return N * factorial(N - 1);
}

template <size_t N>
class Loop
{
public:
    template <typename FuncType>
    static inline void Do(FuncType func)
    {
        Loop<N - 1>::Do(func);
        func(N);
    }
};
template <>
class Loop<0>
{
public:
    template <typename FuncType>
    static inline void Do(FuncType func)
    {
    }
};
inline void DoWork(size_t i)
{
    std::cout << "DoWork(" << i << ")" << std::endl;
}

/*打印元组*/
template <typename TupleType, size_t N>
class tuple_print
{
public:
    tuple_print(const TupleType &t)
    {
        tuple_print<TupleType, N - 1> tp(t);
        std::cout << std::get<N - 1>(t) << std::endl;
    }
};

template <typename TupleType>
class tuple_print<TupleType, 1>
{
public:
    tuple_print(const TupleType &t)
    {
        std::cout << std::get<1 - 1>(t) << std::endl;
    }
};
template <typename TupleType>
class tuple_print<TupleType, 0>
{
public:
     tuple_print(const TupleType &t)
     {

     }
};
template<typename TupleType>
void tuple_printer(const TupleType& tp)
{
    tuple_print<TupleType,std::tuple_size<TupleType>::value> tuple_prnt(tp);
}