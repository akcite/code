## parse

```

#include <stdio.h>

int main() {
  FILE* fp = fopen("../dso/report.txt", "r");

  float maxv[5][3], minv[5][3];

  for (int s = 0; s < 5; s++) {
    for (int i = 0; i < 3; ++i) {
      maxv[s][i] = -100.f;
      minv[s][i] = 100.f;
    }
  }

  int   count = 0;
  float time_sum = 0.f;
  for (int i = 0; i < 1000; ++i) {
    int trial;
    if (fscanf(fp, "%d:\n", &trial) == EOF)
      break;

    int sn;
    float x, y, z;

    for (int s = 0; s < 5; s++) {
      if (fscanf(fp, "%d: %f %f %f\n", &sn, &x, &y, &z) == EOF)
        break;
      if (x > maxv[s][0])
        maxv[s][0] = x;
      if (y > maxv[s][1])
        maxv[s][1] = y;
      if (z > maxv[s][2])
        maxv[s][2] = z;

      if (x < minv[s][0])
        minv[s][0] = x;
      if (y < minv[s][1])
        minv[s][1] = y;
      if (z < minv[s][2])
        minv[s][2] = z;
    }

    float lapse;
    if (fscanf(fp, "%f\n", &lapse) == EOF)
      break;

    count++;
    time_sum += lapse;
  }

  for (int s = 0; s < 5; ++s) {
    printf("%d\n", s);
    printf(" % 1.3f % 1.3f % 1.3f\n", maxv[s][0], maxv[s][1], maxv[s][2]);
    printf(" % 1.3f % 1.3f % 1.3f\n", minv[s][0], minv[s][1], minv[s][2]);
  }

  printf("Total: %d\n", count);
  printf("Mean time: %f\n", time_sum / count);
  return 0;
}
```
