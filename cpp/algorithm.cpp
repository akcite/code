/////////////////////////////////////////////////////////////////////////////////////

// find
// sort
// random_shuffle

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

#include <iostream>
#include <vector>
#include <algorithm>

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

#include <iostream>
#include <vector>
#include <algorithm>

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

#include <iostream>
#include <vector>
#include <algorithm>

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
// sort

#include <iostream>
#include <algorithm>
#include <vector>

bool myfunction(int i, int j) {
  return (i < j);
}

struct myclass {
  bool operator() (int i, int j) {
    return (i < j);
  }
} myobject;

int main() {
  int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
  std::vector<int> myvector(myints, myints + 8);

  std::sort(myvector.begin(), myvector.begin() + 4);

  std::sort(myvector.begin() + 4, myvector.end(), myfunction);

  std::sort(myvector.begin(), myvector.end(), myobject);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
    std::cout << ' ' << *it;
  }

  std::cout << std::endl;

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// unique

#include <iostream>
#include <algorithm>
#include <vector>

bool myfunction( int i, int j) {
  return (i == j);
}

int main() {
  int myints[] = {10, 20, 20, 20, 30, 30, 20, 20, 10};
  std::vector<int> myvector(myints, myints + 9);

  std::sort(myvector.begin(), myvector.end());

  std::vector<int>::iterator it;
  it = std::unique(myvector.begin(), myvector.end());

  myvector.resize(std::distance(myvector.begin(), it));

  std::unique(myvector.begin(), myvector.end(), myfunction);

  std::cout << "myvector contains:";
  for (it = myvector.begin(); it != myvector.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << std::endl;

  return 0;
}

// 10 20 30 

/////////////////////////////////////////////////////////////////////////////////////
// std::find

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    int target = 30;

    auto it = std::find(numbers.begin(), numbers.end(), target);

    if (it != numbers.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////

