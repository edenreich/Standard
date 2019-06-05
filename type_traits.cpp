#include <iostream>
#include <type_traits>

template <typename T>T fac(T a) {
  static_assert(std::is_integral<T>::value, "T not integral");
}

// The definition of the standard type_traits look like the following:
// template <class T> struct is_void;
// template <class T> struct is_integral;
// template <class T> struct is_floating_point;
// template <class T> struct is_array;
// template <class T> struct is_pointer;
// template <class T> struct is_reference;
// template <class T> struct is_member_object_pointer;
// template <class T> struct is_member_function_pointer;
// template <class T> struct is_enum;
// template <class T> struct is_union;
// template <class T> struct is_class;
// template <class T> struct is_function;
// template <class T> struct is_lvalue_reference;
// template <class T> struct is_rvalue_reference;

int main()
{
  fac(10);
  // fac(10.1); // passing a double Throws compile time error "T not integral".
  std::cout << "is void? " << std::is_void<void>::value << std::endl; // true
  std::cout << "is integral? " << std::is_integral<short>::value << std::endl; // true
  std::cout << "is floating point? " << std::is_floating_point<double>::value << std::endl; // true
  std::cout << "is array? " << std::is_array<int[]>::value << std::endl; // true
  std::cout << "is pointer? " << std::is_pointer<int*>::value << std::endl; // true
  std::cout << "is reference? " << std::is_reference<int&>::value << std::endl; // true

  enum Animal {
    cat = 1,
    dog = 2
  };

  std::cout << "is enum? " << std::is_enum<Animal>::value << std::endl; // true
  std::cout << "is lvalue reference? " << std::is_lvalue_reference<int&>::value << std::endl; // true
  std::cout << "is rvalue reference? " << std::is_rvalue_reference<int&&>::value << std::endl; // true
  
  // Sometimes you may want to use mixes of checks
  // For example is_scalar will check to see if: 
  // is_floating_point, is_integral, is_enum, is_pointer or is_member_pointer
  // if none of them match a compile time error will occur.
  std::cout << "is int a scalar? " << std::is_scalar<int>::value << std::endl; // true 
  std::cout << "is float a scalar? " << std::is_scalar<float>::value << std::endl; // true 
  std::cout << "is int pointer a scalar? " << std::is_scalar<int*>::value << std::endl; // true 
  std::cout << "is void a scalar? " << std::is_scalar<void>::value << std::endl; // false 

  class Dog {
  
  protected:
    virtual ~Dog()
    {
      //
    }
  };

  class Chiwawa : public Dog {

  };

  // Assert the base class has virtual destructor
  std::cout << "has virtual destructor? " << std::has_virtual_destructor<Chiwawa>::value << std::endl; // true

  typedef std::add_const<int>::type myConstInt;
  typedef const int myConstInt2;

  // Assert types are the same
  std::cout << "is same? " << std::is_same<myConstInt,myConstInt2>::value << std::endl;

  return 0;
}