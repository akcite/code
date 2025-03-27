### functor transform

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

### nth_element

```
bool myfunction(int i, int j) {
  return (i < j);
}

int main() {
  std::vector<int> myvector;

  for (int i = 1; i < 10; ++i) {
    myvector.push_back(i);
  }

  std::random_shuffle(myvector.begin(), myvector.end());

  std::nth_element(myvector.begin(), myvector.begin() + 4, myvector.end());
  std::nth_element( myvector.begin(), myvector.begin() + 4, myvector.end(), myfunction);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
    std::cout << ' ' << *it;
  }

  std::cout << '\n';

  return 0;
}
```
