### fstream

```
ofstream ofile;
ofile.open("test.txt", std::ofstream::out | std::ofstream::app);
ofile << size << endl;                              // append
ofile.close();

ifstream ifile;
ifile.open((str + "kf_map.txt").c_str(), ifstream::in);
int kf_size;
ifile >> kf_size;
ifile.close();
```

### sprintf

```
char buffer[50];
int n, a=5, b=3;
n = sprintf(buffer, "%d plus %d is %d", a, b, a+b);
```

### carriage return
```
std::cout << "\r\e[K" << sd.id << ": " << sd.fps << " fps [" << sd.x << ", " << sd.y << ", " << sd.th << "]" << std::flush;
```

### printf color

```
#include <stdio.h>

#define AC_RED     "\x1b[31m"
#define AC_GREEN   "\x1b[32m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"

int main (int argc, char const *argv[]) {

  printf(AC_RED     "This text is RED!"     AC_RESET "\n");
  printf(AC_GREEN   "This text is GREEN!"   AC_RESET "\n");
  printf(AC_YELLOW  "This text is YELLOW!"  AC_RESET "\n");
  printf(AC_BLUE    "This text is BLUE!"    AC_RESET "\n");
  printf(AC_MAGENTA "This text is MAGENTA!" AC_RESET "\n");
  printf(AC_CYAN    "This text is CYAN!"    AC_RESET "\n");

  return 0;
}
```

### setfill setw

```
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw
#include <string>
#include <sstream>

int main () {
  std::cout << std::setfill ('x') << std::setw(10);
  std::cout << 77 << std::endl;

  std::stringstream ss("");
  ss << std::setfill('0') << std::setw(6) << 88 << ".png";

  std::cout << "\r" << ss.str() << std::flush;

  return 0;
}

=====
xxxxxxxx77
000088.png
```

### getline

```
std::string sn[3]  = {"-", "0", "1"};
for (int i = 0; i < 3; ++i) {
  
std::string folder = "/home/alan/data/mynt/200225/";

std::string vo_sn = folder + "vo"   + sn[i];
std::string od_sn = folder + "odom" + sn[i];
std::string tf_sn = folder + "tf"   + sn[i];

float fx = 0.f, fy = 0.f, fz = 0.f;
float ax = 0.f, ay = 0.f, az = 0.f, aw = 0.f;
std::string line;
std::ifstream ifs;
std::ofstream ofs;

/* ----- TF ---------------------------------------------------- */

ifs.open((tf_sn + ".txt").c_str(), std::ifstream::in);
ofs.open((tf_sn + ".dat").c_str());

if (!getline(ifs, line))
  return;
  
while (getline(ifs, line)) {
  std::stringstream lstr(line);
  std::string       value;
  
  int count = 1;
  while (getline(lstr, value, ',')) {
    if (count == 6)
      fx = atof(value.c_str());
    if (count == 7)
      fy = atof(value.c_str());
    if (count == 8)
      fz = atof(value.c_str());
    if (count == 9)
      ax = atof(value.c_str());
    if (count == 10)
      ay = atof(value.c_str());
    if (count == 11)
      az = atof(value.c_str());
    if (count == 12)
      aw = atof(value.c_str());

    if (++count > 12)
      break;
  }
  
  ofs << fx << "\t" << fy << std::endl;
}

ifs.close();
ofs.close();
```

### precision

```
kf_file << std::fixed << std::setprecision(16);
```

