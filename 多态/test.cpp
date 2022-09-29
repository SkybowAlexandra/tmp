#include <string>
#include <iostream>

class Animal
{
public:
    virtual void speak() = 0;
};

class Cat : public Animal{
    virtual void speak()
    {
        std::cout << "猫在说话" << std::endl;
    }

};

class Dog : public Animal{
    virtual void speak()
    {
        std::cout << "狗在说话" << std::endl;
    }
};

void test01(Animal *animal)
{
    animal->speak();
}

int main()
{
    Animal *animal = new Dog;
    Animal *animal2 = new Cat;
   
    test01(animal);
    test01(animal2);
}

