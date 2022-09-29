#include <iostream>
#include <string>


class Dog//注意：与多态不同，不需要有类阶层（简单说不需要继承啥接口）
{
public:
    void speak()
    {
       std::cout << "狗在说话" << std::endl;
    }
};

class Cat
{
public:
    void speak()
    {
       std::cout << "猫在说话" << std::endl;
    }

};

template<typename T>
class animal
{
public:
    void speak()
    {
      decorator.speak();
    }
private:
    T decorator;
};

int main(int argc, char* argv[])
{
   animal<Dog> p1;
   p1.speak();
   
   animal<Cat> p2;
   p2.speak();

    return 0;
}