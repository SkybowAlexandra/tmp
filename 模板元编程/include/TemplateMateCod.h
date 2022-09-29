#pragma once
#include <tuple>
#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <utility>
#include <array>
/*constexpr 逻辑判断*/
template <typename TupleType, std::size_t n = std::tuple_size<TupleType>::value>
constexpr void tuple_print(const TupleType &t)
{
    if constexpr (n > 1) //必须要 n > 1 才能继续递归
    {
        tuple_print<TupleType, n - 1>(t);
    }
    std::cout << std ::get<n - 1>(t) << std::endl;
}

/*类似for 循环 整数序列*/
// std::index_sequence
// std::index_sequence_for
//元组遍历打印
template <typename Tuple, std::size_t... Indices>                                  // size_t ... Indices 参数包也可以用在非类型模板参数,这里是size_t 所以是整数
constexpr auto tuple_print_helper(const Tuple &t, std::index_sequence<Indices...>) //代表了一套的整数序列:比如传5 会变成 1 2 3 4 5
{
    ((std::cout << std::get<Indices>(t) << std::endl), ...);
}
template <typename... Args>
constexpr auto tuple_print_2(const std::tuple<Args...> &t)
{
    tuple_print_helper(t, std::index_sequence_for<Args...>()); //编译期产生的序列
}

/*类型萃取 示例*/
//选择分支
template <typename T>
void process_impl(const T &t, std::true_type)
{
    std::string str = std::to_string(t);
    std::cout << "整数转换string:  " << str << std::endl;
}

template <typename T>
constexpr void process_impl(const T &t, std::false_type)
{
    std::stringstream ss;
    ss << t;
    std::cout << "没有将整数转换成string: " << ss.str() << std::endl;
}
template <typename T>
constexpr void process(const T &t)
{
    // if constexpr(std::is_integral<T>::value)
    process_impl(t, typename std::is_integral<T>::type()); // typename 告诉编译器我这里是类型
}

/*类型检查*/

/*typename enable_if<...,bool>::type*/
template <typename T1, typename T2>
constexpr typename std::enable_if_t<std::is_same_v<T1, T2>, bool> check_type(const T1 &t1, const T2 &t2)
{
    std::cout << "T1和T2是同一种类型" << std::endl;
    return true;
}
/*如果is_same_v 为false bool不会定义,函数变成void ,但是有第二版本,所以不会报错,这个特性叫SFINAE: */
template <typename T1, typename T2>
constexpr typename std::enable_if_t<!std::is_same_v<T1, T2>, bool> check_type(const T1 &t1, const T2 &t2)
{
    std::cout << "T1和T2是不是同一种类型" << std::endl;
    return false;
}
/*构造函数类型检查,检查子类是不是从某个父类继承过来的*/

class IsDoable
{
public:
    void doit() const noexcept
    {
        std::cout << "parent call doit" << std::endl;
    }
};
class Derived : public IsDoable
{
public:
    void predoit() const noexcept
    {
        std::cout << "Derived call predoit" << std::endl;
    }
};
#if 0
template <typename T>
typename std::enable_if_t<std::is_base_of_v<IsDoable, T>, void> call_doit(const T &t)
{
    t.predoit();
    t.doit();
}
template <typename T>
typename std::enable_if_t<!std::is_base_of_v<IsDoable, T>, void> call_doit(const T &t)
{
    std::cout << "cant call doit" << std::endl;
}
#else
/*使用常量表达合并*/

template <typename T>
void call_doit([[maybe_unused]] const T &t)
{
    if constexpr (std::is_base_of_v<IsDoable, T>) 
    {
        t.doit();
    }
    else
    {
        std::cout << "cant call doit" << std::endl;
    }
}
#endif

// debugging aid
template <typename T, T... ints>
constexpr void print_sequence(std::integer_sequence<T, ints...> int_seq)
{
    std::cout << " sequence 的大小: " << int_seq.size() << ": ";
    ((std::cout << ints << ' '), ...);
    std::cout << '\n';
}

// 数组转换元组
template <typename Array, std::size_t... I>
auto a2t_impl(const Array &a, std::index_sequence<I...>)
{
    return std::make_tuple(a[I]...);
}

template <typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N> &a)
{
    return a2t_impl(a, Indices{});
}

// 打印元组

template <class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch, Tr> &os,
                      const Tuple &t,
                      std::index_sequence<Is...>)
{
    ((os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), ...);
}

template <class Ch, class Tr, class... Args>
auto &operator<<(std::basic_ostream<Ch, Tr> &os,
                 const std::tuple<Args...> &t)
{
    os << "(";
    print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
    return os << ")";
}