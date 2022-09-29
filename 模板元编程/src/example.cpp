#include "TemplateMateCod.h"
#include <complex>
int main(int argc, char *argv[])
{
    std::tuple tp = std::make_tuple(24, "abc", 3.14);

    std::cout << "tuple_print: ";
    tuple_print(tp);
    std::cout << "tuple_print2: ";
    tuple_print_2(tp);
    /*类型萃取,详情见msdn*/
    std::cout << std::is_integral<int *>::value << std::endl; //不是整数类型,是指针类型
    std::cout << std::is_integral<int>::value << std::endl;   // 是整数类型
    //类似 using std::is_integral_v<int> = std::is_integral_<int>::value
    std::cout << std::is_integral_v<int> << std::endl; //所有的_v版本都是返回的值
    /*类型萃取*/
    process("hjello");
    process(3);
    process(-3);
    std::complex<double> cplx(2,3);
    process(cplx);

    /*检查类型*/
    check_type(22,3.14);
    check_type(22,22);
    /*类类型检查*/
    Derived d;
    call_doit(d);
    call_doit(1234);
    print_sequence(std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{});
    print_sequence(std::make_integer_sequence<int, 20>{});
    print_sequence(std::make_index_sequence<10>{});
    print_sequence(std::index_sequence_for<float, std::iostream, char>{});

    std::array<int, 4> array = {1, 2, 3, 4};

    // 将数组转换为元组
    auto tuple = a2t(array);

   // 做编译期间的静态检查
    static_assert(std::is_same<decltype(tuple),
                               std::tuple<int, int, int, int>>::value,
                  "");

    // /*打印元组*/
    std::cout << "数组转换元组: " << tuple << '\n';

    return 0;
}
