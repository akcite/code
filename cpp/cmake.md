
## simple

```
cmake_minimum_required(VERSION 2.8...3.13)
project(cplusplus_test LANGUAGES C CXX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(map_test src/map_test.cpp)
```

## C++11

```
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(MyProject src/main.cpp)
```

