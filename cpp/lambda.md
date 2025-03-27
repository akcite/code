## Lambda

| Operator | Notes |
| -------- | ---------------------------------------------- |
| [ ]	| Capture nothing (or, a scorched earth strategy?) |
| [&]	| Capture any referenced variable by reference |
| [=]	| Capture any referenced variable by making a copy |

```
auto TransferCoordinates = [](cv::Vec2f pt) {
  int u = 249 - static_cast<int>(pt(1) * 10.);
  int v = 499 - static_cast<int>(pt(0) * 10.);

  return cv::Vec2i(u, v);
};
```
