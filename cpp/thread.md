### thread

```
#include <iostream>
#include <thread>

void foo() {

}

void bar(int x) {

}

int main() {
  std::thread first(foo);
  std::thread second(bar, 0);

  std::cout << "main, foo and bar now execute concurrently..." << std::endl;

  first.join();
  second.join();

  std::cout << "foo and bar completed." << std::endl;

  return 0;
}
```

### mutex

```
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_block(int n, char c) {
  // std::unique_lock<std::mutex> lck(mtx);
  for (int i = 0; i < n; ++i) {
    std::cout << c;
  }

  std::cout << std::endl;
}

int main() {
  std::thread th1(print_block, 50, '*');
  std::thread th2(print_block, 50, '$');

  th1.join();
  th2.join();

  return 0;
}
```



