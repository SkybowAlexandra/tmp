constexpr if 如果条件不成立，代码不会编译

判断两个类型之间关系的traits:

template< typename T, typename U>
struct is_same;	判断两个类型是否相同

template< typename T, typename U>
struct is_base_of;	判断类型T是否是类型U的基类

template< typename T, typename U>
struct is_convertible;	判断类型T能否转换为类型U

类型的转换 traits :
template< typename T>
struct remove_const;	移除const

template< typename T>
struct add_const;	添加const

template< typename T>
struct remove_reference;	移除引用

template< typename T>
struct add_lvalue_reference;	添加左值引用

template< typename T>
struct add_rvalue_reference;	添加右值引用

template< typename T>
struct remove_extent;	移除数组顶层的维度，
比如 int [3][3][2] 变为 int [3][2]

template< typename T>
struct remove_all_extent;	移除数组所有的维度，比如 int [3][3][2] 变为 int

template< typename T>
struct remove_pointer;	移除指针

template< typename T>
struct add_pointer;	添加指针

template< typename T>
struct decay;	移除cv或者添加指针

template< typename .... T>
struct common_type;	获取公共类型

msdn: https://docs.microsoft.com/zh-cn/previous-versions/ff926129(v=vs.110) 