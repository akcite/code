## Unix time

It measures time by the number of non-leap seconds that have elapsed since 00:00:00 UTC on 1 January 1970, the Unix **epoch**.

```
auto now = std::chrono::high_resolution_clock::now();
auto now_nanosec = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());
std::string current_time = std::to_string(now_nanosec.count());
std::cout << current_time << std::endl;

now = std::chrono::high_resolution_clock::now();
now_nanosec = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());
std::cout << std::to_string(now_nanosec.count()) << std::endl;

===

1626375435423866387
1626375435423895344
```

## Duration

```
#include <iostream>
#include <chrono>

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();
    
    double d = 0.1;
    for (int i = 0; i < 10000000; ++i) {
      d = d * d;
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
    std::chrono::duration<double, std::micro> fp_us = t2 - t1;
    
    std::cout << "for took " << fp_ms.count() << " ms" << std::endl;
    std::cout << "for took " << fp_us.count() << " us" << std::endl;
}

===

g++ -std=c++11 chrono.cpp 
./a.out

for took 22.2169 ms
for took 22216.9 us
```

## Date, HH:MM:SS

```
#include <iostream>
#include <ctime>

int main() {
  std::time_t now = std::time(NULL);
  std::tm * ptm = std::localtime(&now);
  char buffer[256];
  // Format: Mo, 15.06.2009 20:20:00
  std::strftime(buffer, sizeof(buffer), "%a, %d.%m.%Y %H:%M:%S", ptm);
  
  std::cout << buffer << std::endl;

  return 0;
}

=====
Thu, 01.07.2021 15:24:03
```

## ctime

```
#include <ctime>

void f() {
  using namespace std;
  clock_t begin = clock();

  code_to_time();

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
}
```

```
#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
   time_t now = time(0);

   cout << "Number of sec since January 1,1970 is:: " << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year:" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<< ltm->tm_mday << endl;
   cout << "Time: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}

===
year month day hour min sec
```

