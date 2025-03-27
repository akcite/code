/////////////////////////////////////////////////////////////////////////////////////
// SIGSEGV

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

void baz() {
 int *foo = (int*)-1; // make a bad pointer
  printf("%d\n", *foo);       // causes segfault
}

void bar() { baz(); }
void foo() { bar(); }

int main(int argc, char **argv) {
  signal(SIGSEGV, handler);   // install our handler
  foo(); // this will call foo, bar, and baz.  baz segfaults.
}

/*
$ gcc -g -rdynamic ./test.c -o test
*/

/////////////////////////////////////////////////////////////////////////////////////
// compile

// vi hello.cpp

#include <iostream>
int main () {
  std::cout << "Hello\n" << std::endl;
  return 0;
}

/*
:wq

g++ hello.cpp
./a.out

-std=c++11

combine .o object files
$ ld -r a.o b.o -o c.o
$ gcc c.o other.o -o executable
$ ./executable

https://stackoverflow.com/questions/2980102/combine-two-gcc-compiled-o-object-files-into-a-third-o-file

*/

/////////////////////////////////////////////////////////////////////////////////////
