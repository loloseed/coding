/*
 *
 */
#include <iostream>

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

int main() {
  Derived d;
  d.interface();
  Derived::static_func();

  Derived2 d2;
  d2.interface();
  Derived2::static_func();
  return 0;
}
