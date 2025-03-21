### Unix time

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


#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat im0 = imread("9bn.jpg", IMREAD_GRAYSCALE), ds0;
    
    auto t1 = std::chrono::high_resolution_clock::now();

    vector<cv::KeyPoint> kp0;
    //~ for (int i = 0; i < 1000; ++i) {
    Ptr<GFTTDetector> detector = GFTTDetector::create(60, 0.01, 10);
    detector->detect(im0, kp0);

    auto t2 = std::chrono::high_resolution_clock::now();

    Ptr<ORB> extractor = ORB::create();
    extractor->compute(im0, kp0, ds0);
    //~ }
    cout << kp0.size() << endl;

    auto t3 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
    std::chrono::duration<double, std::milli> fp_us = t3 - t2;
    
    std::cout << "for took " << fp_ms.count() << " ms" << std::endl;
    std::cout << "for took " << fp_us.count() << " ms" << std::endl;
}

/*
g++ --std=c++11 -I/usr/local/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"test_time.d" -MT"test_time.o" -o "test_time.o" "./test_time.cpp"
g++ -L/usr/local/lib -o "opencv"  ./test_time.o   -lopencv_core -lopencv_highgui -lopencv_features2d -lopencv_flann -lopencv_imgproc -lopencv_calib3d -lopencv_imgcodecs -lopencv_videoio -lopencv_xfeatures2d -lopencv_ccalib


g++ --std=c++11 -I/usr/local/include -I/opt/ros/kinetic/include -I/opt/ros/kinetic/include/opencv-3.3.1-dev -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"test_time.d" -MT"test_time.o" -o "test_time.o" "./test_time.cpp"
g++ -L/usr/local/lib -L/opt/ros/kinetic/lib/aarch64-linux-gnu -o "opencv"  ./test_time.o   -lopencv_core3 -lopencv_highgui3 -lopencv_features2d3 -lopencv_flann3 -lopencv_imgproc3 -lopencv_calib3d3 -lopencv_imgcodecs3 -lopencv_videoio3 -lopencv_xfeatures2d3 -lopencv_ccalib3
*/


#include <ctime>

void f() {
  using namespace std;
  clock_t begin = clock();

  code_to_time();

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
}
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

