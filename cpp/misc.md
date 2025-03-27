### template

```
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
```

### regex

```
char regex_filename[] = “[a-zA-Z_] [a-zA-Z_0-9]*\\.[a-zA-Z0-9]+”;
[a-zA-Z_]     : a letter (lowercase and then uppercase) or an underscore
[a-zA-Z_0-9]* : zero or more characters, in which each may be a letter, or an underscore or a digit
\\.           : a literal dot
[a-zA-Z0-9]+  : one or more characters, in which each may be a letter or digit
```

### hypot

```
c = hypot(a, b);  // h = √(a^2+b^2)
```

### const

| variables | notes |
| -------------------------- | -------------------------------------- |
| const int Constant1=96; | integer constant |
| const int * Constant2 | variable pointer to a constant integer |
| int const * Constant2 | same |
| int * const Constant3 | constant pointer to a variable integer |
| int const * const Constant4 | constant pointer to a constant integer |
| const char *Function1() | return value is unalterable |


### square root

```
sqrt(x*x+y*y) → hypot(x,y)

x≤sqrt(y) → x*x≤y or x≤y/x

sqrt(x*x+y*y+z*z) → hypot(x,hypot(y,z))
```

### enum

```
enum Days {Saturday, Sunday, Tuesday, Wednesday, Thursday, Friday};
Days day = Saturday;
if (day == Saturday)
```

```
enum class Days {
    SUNDAY,
    MONDAY,
    // ... etc.
}

// ...

if (day == Days::SUNDAY)
```

### tuple

```
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
```

### stringstream

```
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
```

