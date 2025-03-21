### thread

```
#include <thread>

thread* thr = new thread[param->pyr_levels];
for (int l = 0; l < param->pyr_levels; ++l)
  thr[l] = std::thread(&ImageProcess::Process, ip, l, frame);

for (int l = 0; l < param->pyr_levels; ++l)
  thr[l].join();

delete[] thr;
```
