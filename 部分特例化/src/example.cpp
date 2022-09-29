#include "Grid.h"
#include "TemplateFunction.h"
#include <string>

void is_index(size_t iFind)
{
    if (iFind == NOT_FOUND_INDEX)
        std::cout << "not found " << std::endl;
    else
        std::cout << "the value in the array index is: " << iFind << std::endl;
}
int main(void)
{
    std::cout << "===============常规虚函数实例化对象============" << std::endl;
    FullClass fs;
    fs.func1();
    fs.func2();
    std::cout << "================普通模板实例化对象=============" << std::endl;
    Grid<int, 10, 10> grid;
    std::cout << "grid.at(1,1).value() is value : " << grid.at(1, 1).value() << std::endl;
    std::cout << "===============部分特例化实例化对象=============" << std::endl;
    Grid<std::string, 10, 10> strgrid;
    std::cout << strgrid.at(0, 0).value() << std::endl;
    std::cout << "===============指针特例化实例化对象=============" << std::endl;
    Grid<int *, 10, 10> pontgrid;
    std::cout << *pontgrid.at(5, 0).value() << std::endl;
    std::cout << "===================普通模板函数=============================" << std::endl;
    int intarr[7] = {1, 2, 3, 4, 5, 6, 7};
    size_t iFind = Find(3, intarr, 7);
    is_index(iFind);
    iFind = NOT_FOUND_INDEX;
    std::cout << "=================指针重载模板函数============================" << std::endl;
    int *pArray[7] = {new int(1),new int(2),new int(3),new int(4)};
    int *valueToFind = new int(4);
    iFind = Find(valueToFind,pArray,7); 
    is_index(iFind);
    iFind = NOT_FOUND_INDEX;
    std::cout << "=================const char * 模板函数============================" << std::endl;
    const char *words[7] = {"one", "two", "three", "four"};
    const char *strToFind = "three";
    iFind = Find<const char *>(strToFind, words, 4);
    is_index(iFind);
    iFind = NOT_FOUND_INDEX;
    return 0;
}


#if 0
int main(int argc, char *argv[])
{
    size_t iFind = NOT_FOUND_INDEX;
    /*常规虚函数实例化对象*/
    // FullClass fc;
    // fc.func1();
    // Grid<int, 10, 10> grid;
    //***************************************************//
    /*部分特例化*/
    // Grid<std::string, 10, 10> strgrid;
    // std::cout << strgrid.at(0, 0).value() << std::endl;
    //***************************************************//
    /*指针特例化*/
    // Grid<int *, 10, 10> pintgrid;
    // std::cout << *pintgrid.at(5, 0).value() << std::endl;
    //***************************************************//

    /*模板函数 */
    //   int intarr[7] = {1, 2, 3, 4, 5, 6, 7};
    //    iFind = Find(3, intarr, 7);
    //***************************************************//

#if 0
    /*C++标准规定不支持函数特例化*/
    //int valueToFind = 5;
   // size_t iFind = Find(&valueToFind, &intarr, 7);
   /*使用另一个模板重载函数*/
    const char* words[7] = {"one","two","three","four"};
    const char *strToFind = "three";
    size_t iFind = Find<const char *>(strToFind, words, 4);
//***************************************************//
#endif
/*为指针重载*/
#if 1
    int *pArray[7] = {new int(1),new int(2),new int(3),new int(4)};
    int *valueToFind = new int(4);
    iFind = Find(valueToFind,pArray,7); 
    if (iFind == NOT_FOUND_INDEX)
    {
        std::cout << "not found " << std::endl;
    }
    else
        std::cout << "the value in the array index is: " << iFind << std::endl;
    iFind = NOT_FOUND_INDEX;

#endif
#if 1
    const char *words[7] = {"one", "two", "three", "four"};
    const char *strToFind = "three";
    iFind = Find<const char *>(strToFind, words, 4);
    // iFind = Find<char *>(sa,one_two_thead ,4);
    if (iFind == NOT_FOUND_INDEX)
    {
        std::cout << "not found " << std::endl;
    }
    else
        std::cout << "the value in the array index is: " << iFind << std::endl;
#endif
    return 0;
}
#endif
