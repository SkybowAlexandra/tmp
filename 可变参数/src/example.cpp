/********************************************************************************
 * @文件名:
 * @作者: 赵
 * @版本: 1.0
 * @时间: 2021-
 * @格式:
 * @说明:
 ********************************************************************************/
#include "VariadicTemplate.h"


int main(int argc, char *argv[])
{


    //可变模板参数和完美转发
    std::string str("abc");
    processValues(1, std::move(str), 3.14, "hello wolrd");

    /*C++混入模式*/
    MyInterface<ReadInterface, WriteInterface, PrintInterface> ReadWriteInterface;
    ReadWriteInterface.Read();
    ReadWriteInterface.Write();
    ReadWriteInterface.Print();
    /*折叠表达式*/
    printValues(1, "2", "231"); //(std::cout << 1<< " ") ,(std::cout << "2" << " "),(std::cout <<231 << " ")
    std::cout << "R: " << RightFolderSumOfValue(1, 2, 3, 4, 5) << std::endl;
    std::cout << "L: " << leftFolderSumOfValue(1, 2, 3, 4, 5) << std::endl;
    /*开始元编程计算乘阶*/
    std::cout << Factorial<5>::value << std::endl;
    std::cout << factorial(5) << std::endl;
    Loop<3>::Do(DoWork);
    /*打印元组*/
    std::tuple<int, std::string, double> isd_tuple = std::make_tuple(2, "ABC", 3.14);
/*     std::cout << std::get<0>(isd_tuple) << std::endl;
    tuple_print < std::tuple<int, std::string, double>,
     std::tuple_size<std::tuple<int, std::string, 
     double>>::value> tuple_prnt(isd_tuple); */
    tuple_printer(isd_tuple);
    return 0;
}
