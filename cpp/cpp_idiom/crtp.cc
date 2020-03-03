/*
 * curiously recurring template pattern(CRTP),功能：
 * 1. 编译时静态多态替换运行时动态多态；
 * 2. 继承用类本身实现化的模板类的某种特性(参见crtp wikipedia的object counter)；
 */
#include <iostream>

/* ----- static polymorphism start ----- */
template <class Derived> 
class Base
{
public:
    void interface()
    {
        // ...
        std::cout << "called interface" << std::endl;
        static_cast<Derived*>(this)->implementation();
        // ...
    }
    static void static_func()
    {
        // ...
        std::cout << "called static_func" << std::endl;
        Derived::static_sub_func();
        // ...
    }
};
class Derived : public Base<Derived>
{
public:
    void implementation() {
        std::cout << "called Derived::implementation" << std::endl;
    }
    static void static_sub_func() {
        std::cout << "called Derived::static_sub_func" << std::endl;
    }
};
class Derived2 : public Base<Derived2>
{
public:
    void implementation() {
        std::cout << "called Derived2::implementation" << std::endl;
    }
    static void static_sub_func() {
        std::cout << "called Derived2::static_sub_func" << std::endl;
    }
};
template <class T>
void interface(Base<T>& obj) {
  obj.interface();
}
template <class T>
void static_func() {
  Base<T>::static_func();
}
/* ----- static polymorphism end ----- */

int main() {
/* ----- static polymorphism start ----- */
  // 统一的interface和static_func<>接口，传入不同的类实例和类模板参数，实现静态多态；
  Derived d;
  Derived2 d2;
  interface(d);
  interface(d2);
  static_func<Derived>();
  static_func<Derived2>();
/* ----- static polymorphism end ----- */
  return 0;
}
