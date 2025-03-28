/////////////////////////////////////////////////////////////////////////////////////
// template

#include <iostream>

template <typename T>  // typename -> class, no difference
class TClass {
  public:
  TClass(T value) : data(value) {}

  T getData() const {
    return data;
  }

  private:
  T data;
};

int main() {
  TClass<int> intObject(10);
  TClass<std::string> stringObject("Hello");

  std::cout << intObject.getData() << std::endl;
  std::cout << stringObject.getData() << std::endl;

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// regex

char regex_filename[] = “[a-zA-Z_] [a-zA-Z_0-9]*\\.[a-zA-Z0-9]+”;
[a-zA-Z_]     : a letter (lowercase and then uppercase) or an underscore
[a-zA-Z_0-9]* : zero or more characters, in which each may be a letter, or an underscore or a digit
\\.           : a literal dot
[a-zA-Z0-9]+  : one or more characters, in which each may be a letter or digit

// hypot

c = hypot(a, b);  // h = √(a^2+b^2)

/////////////////////////////////////////////////////////////////////////////////////
// const

| variables                   | notes                                   |
| --------------------------  | --------------------------------------  |
| const int Constant1=96;     | integer constant                        |
| const int * Constant2       | variable pointer to a constant integer  |
| int const * Constant2       | same                                    |
| int * const Constant3       | constant pointer to a variable integer  |
| int const * const Constant4 | constant pointer to a constant integer  |
| const char *Function1()     | return value is unalterable             |

/////////////////////////////////////////////////////////////////////////////////////
// square root

sqrt(x*x+y*y) → hypot(x,y)

x≤sqrt(y) → x*x≤y or x≤y/x

sqrt(x*x+y*y+z*z) → hypot(x,hypot(y,z))

/////////////////////////////////////////////////////////////////////////////////////
// enum

enum Days {Saturday, Sunday, Tuesday, Wednesday, Thursday, Friday};
Days day = Saturday;
if (day == Saturday)


enum class Days {
    SUNDAY,
    MONDAY,
    // ... etc.
}

// ...

if (day == Days::SUNDAY)

/////////////////////////////////////////////////////////////////////////////////////
// tuple

#include <iostream>
#include <functional>
#include <tuple>

int main() {
  auto first = std::make_tuple(10, 'a');

  const int a = 0;
  int b[3];

  auto second = std::make_tuple(a, b);

  auto third = std::make_tuple(std::ref(a), "abc");

  std::cout << "third contains: " << std::get<0>(third);
  std::cout << " and " << std::get<1>(third);
  std::cout << std::endl;

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// stringstream

#include <string>
#include <iostream>
#include <sstream>

int main() {
  std::stringstream ss;
  ss.str("Example string");
  std::string s = ss.str();
  std::cout << s << std::endl;
  return 0;
}


  ss << "Example string";
  ss << " " << 100;
  std::cout << ss.str() << std::endl;

/////////////////////////////////////////////////////////////////////////////////////
// overloading

#include <iostream>

class Calculator {
  public:
  int add(int a, int b) {
    return a + b;
  }

  double add(double a, double b) {
    return a + b;
  }

  int add(int a, int b, int c) {
    return a + b + c;
  }
};

int main() {
  Calculator calc;
  int sum1 = calc.add(2, 3);
  double sum2 = calc.add(2.5, 3.5);
  int sum3 = calc.add(1, 2, 3);

  std::cout << sum1 << " " << sum2 << " " << sum3 << std::endl;
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// overriding

#include <iostream>

class Animal {
  public:
  virtual void makeSound() {
    std::cout << "Generic animal sound" << std::endl;
  }
};

class Dog : public Animal {
  public:
  void makeSound() override {
    std::cout << "Woof!" << std::endl;
  }
};

int main() {
  Animal* animal1 = new Animal();
  Animal* animal2 = new Dog();

  animal1->makeSound();
  animal2->makeSound();

  delete animal1;
  delete animal2;

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// lvalue & rvalue

#include <iostream>

void foo(int& a) {
  std::cout << "Here" << std::endl;
}

void foo(int&& a) {
  std::cout << "There" << std::endl;
}

int main() {
  int a = 10;

  foo(a);
  foo(10);

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
