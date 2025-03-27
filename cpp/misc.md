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

### functor

```
#include <cassert>
#include <vector>
#include <algorithm>

struct add_x {
  add_x(int val) : x(val) {}

  int operator() (int y) const {
    return x + y;
  }

  private:
  int x;
};

int main() {
  add_x add42(42);
  int i = add42(8);
  assert (i == 50);

  std::vector<int> in;
  for (int i = 0; i < 10; ++i) {
    in.push_back(i);
  }
  std::vector<int> out(in.size());

  std::transform(in.begin(), in.end(), out.begin(), add_x(1));

  for (int i = 0; i < 10; ++i) {
    assert(out[i] == in[i] + 1);
  }

  return 0;
}
```


