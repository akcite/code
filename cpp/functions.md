## GetFileNames

```
void GetFileNames(std::string dir, std::vector<std::string>& file_list) {
  if (dir.back() != '/') {
    dir += "/";
  }

  DIR *dp;
  struct dirent *dirp;
  if ((dp = opendir(dir.c_str())) == nullptr) {
    std::cout << "Error(" << errno << ") opening " << dir << std::endl;
  }

  while ((dirp = readdir(dp)) != nullptr) {
    file_list.push_back(dir + std::string(dirp->d_name));
  }
  closedir(dp);

  sort(file_list.begin(), file_list.end());
  file_list.erase(file_list.begin()); //.
  file_list.erase(file_list.begin()); //..
}
```

## Home directory

```
#include <pwd.h>

struct passwd *pw = getpwuid(getuid());
std::cout << std::string(pw->pw_dir) << std::endl;
```
