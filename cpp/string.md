### std::string to number

```
c++11

int std::stoi( str )
long std::stol(string)
float std::stof(string)
double std::stod(string)
```

### substr

```
string str("/usr/bin/test.txt");
size_t found = str.find_last_of("/");
cout << " path: " << str.substr(0,found) << '\n';  // pos, length 
cout << " file: " << str.substr(found+1) << '\n';  // pos to end

===output===
path: /usr/bin
file: test.txt
```

### fill

```
std::string(10, ‘ ‘);      // fill 10 spaces.
```

## last n characters
```
input.substr(input.size() - n);
```





