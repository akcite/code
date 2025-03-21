### insert

```
a_vector.insert(a_vector.end(), b_vector.begin(), b_vector.end());
```

### resize

```
std::vector<int> myvector;

// set some initial content:
for (int i=1;i<10;i++) myvector.push_back(i);

myvector.resize(5);
myvector.resize(8, 100);
myvector.resize(12);
===
1 2 3 4 5 100 100 100 0 0 0 0
```

### initialize

```
// Create a vector of size n with all values as 10.
vector<int> vect(n, 10);

vector<int> vect{10, 20, 30};
```

### pop_back

```
vector<int> v;
for (int i = 0; i < 10; ++i)
  v.push_back(i);

for (uint i = 0; i < v.size(); ++i) {
  if (i == 2 || i == 8) {
    v[i] = v.back();
    v.pop_back();
  }
}

for (auto i : v)
  cout << i << " ";
cout << endl;

===
0 1 9 3 4 5 6 7
```

### inheritance

```
#include <iostream>
#include <vector>

using namespace std;

class int_vec : public vector<int> {
public:
  int value;
  // nothing yet!
};  // class int_vec

int main() {
  int_vec v;
  v.value = 10;

  v.push_back(4);
  v.push_back(5);
  v.push_back(1);

  for (int n : v)
    cout << n << "\n";

  cout << v.value << endl;
  cout << v[1] << endl;
}

---
4
5
1
10
5
```
