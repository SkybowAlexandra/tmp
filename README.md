特化的重载
1、对不同类型进行不同方式的处理需要用到特化 
2、整数也可以作为参数,只支持整数或者枚举类型,为什么不把整数作为参数而作为尖括号
3、编译期常量的限制就在于他不能通过运行时变量组成的表达式来指定
4、将模板声明和实现放在.h和.cpp里 不建议这么做,必须要在.cpp增加显式编译模板的声明,违反了面向对象的开闭原则
5、模板可以自动推断类型，从而参与重载
6、inline不能让他强制,完全看编译器
7、int && 能自动转换成 int const &,但不能转换成int &
8、typeid（数据类型 / 表达式）：运算符用来获取一个表达式的类型信息,typeid是不准的
9、std::decay 类型完全退化结合std::is_same<typename std::decay<T>::type, U>::type 使用 ,如果是std::decay_t就不需要typename
10、无捕获的lambdda可以传为函数指针