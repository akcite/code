## mask

```
class Mask {
  public:
  Mask(int rows, int cols) : rows_(rows), cols_(cols) {
    data = new bool[rows_ * cols_];
    memset(data, 0, rows_ * cols_);
  };

  ~Mask() {
    delete data;
  }

  bool& operator ()(int r, int c) {
    return data[rows_ * r + c];
  }

  bool* data;
  int rows_;
  int cols_;
};
```
