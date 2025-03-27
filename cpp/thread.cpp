/////////////////////////////////////////////////////////////////////////////////////
// thread

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

/////////////////////////////////////////////////////////////////////////////////////
// mutex

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_block(int n, char c) {
  std::unique_lock<std::mutex> lck(mtx);
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

/////////////////////////////////////////////////////////////////////////////////////
// atomic

#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>         // std::vector

std::atomic<bool> ready (false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m (int id) {
  while (!ready) { std::this_thread::yield(); }      // wait for the ready signal
  for (volatile int i=0; i<1000000; ++i) {}          // go!, count to 1 million
  if (!winner.test_and_set()) { std::cout << "thread #" << id << " won!\n"; }
};

int main ()
{
  std::vector<std::thread> threads;
  std::cout << "spawning 10 threads that count to 1 million...\n";
  for (int i=1; i<=10; ++i) threads.push_back(std::thread(count1m,i));
  ready = true;
  for (auto& th : threads) th.join();

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
