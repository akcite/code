/////////////////////////////////////////////////////////////////////////////////////
// functor & transform

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

/////////////////////////////////////////////////////////////////////////////////////
// nth_element

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

// ===
// 4th element is like sorted order.

/////////////////////////////////////////////////////////////////////////////////////
// for_each

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

struct myclass {           // function object type:
  void operator() (int i) {std::cout << ' ' << i;}
} myobject;

int main () {
  std::vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);

  std::cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myfunction);
  std::cout << '\n';

  // or:
  std::cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myobject);
  std::cout << '\n';

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// rotate

int main() {
  std::vector<int> myvector;

  for (int i = 1; i < 10; ++i) {
    myvector.push_back(i);
  }

  std::rotate(myvector.begin(), myvector.begin() + 3, myvector.end());

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
    std::cout << ' ' << *it;
  }

  std::cout << '\n';

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// random_shuffle

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// random generator function:
int myrandom (int i) { return std::rand()%i;}

int main () {
  std::srand ( unsigned ( std::time(0) ) );
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  std::random_shuffle ( myvector.begin(), myvector.end() );

  // using myrandom:
  std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////

