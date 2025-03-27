## std::string to number

```
// c++11

int std::stoi( str )
long std::stol(string)
float std::stof(string)
double std::stod(string)
```

## number to string

```
for (const double f : {1.23456789555555, 23.43, 1e-9, 1e40, 1e-40, 123456789.0}) {
  std::cout << "to_string:\t" << std::to_string(f) << revision() << '\n';
}

===
1.234568
```

## get character

```
// char& operator[] (size_t pos)

std::string str ("Test string");
std::cout << str[0];

// char& at (size_t pos);

std::string str ("Test string");
std::cout << str.at(0);

// char& front();
// char& back();
```

## substr

```
string str("/usr/bin/test.txt");
size_t found = str.find_last_of("/");
cout << " path: " << str.substr(0,found) << '\n';  // pos, length 
cout << " file: " << str.substr(found+1) << '\n';  // pos to end

===output===
path: /usr/bin
file: test.txt
```

## fill

```
std::string(10, ‘ ‘);      // fill 10 spaces.
```

## last n characters
```
input.substr(input.size() - n);
```

## split filename

```
std::string file_name ="/home/alan/documents.txt";
std::string::size_type slash_pos = file_name.find_last_of('/');
std::string::size_type dot_pos = file_name.find('.');

std::string dir_name = file_name.substr(0, slash_pos);
std::string name_only = file_name.substr(slash_pos + 1);
std::string extension = file_name.substr(dot_pos + 1, file_name.length() - dot_pos);
    
std::cout << dir_name << std::endl;
std::cout << name_only << std::endl;
std::cout << extension << std::endl;

=============

/home/alan/documents
txt
```

## ROS time to std::string

```
std::to_string(ros::Time::now().toSec()) + ".jpg"
```

## Convert from strings

| function | usage |
| ------------- | --------------------------------------- |
| stoi	| Convert string to integer (function template) | 
| stol	| Convert string to long int (function template) | 
| stoul	| Convert string to unsigned integer (function template) | 
| stoll	| Convert string to long long (function template) | 
| stoull	| Convert string to unsigned long long (function template) | 
| stof	| Convert string to float (function template) | 
| stod	| Convert string to double (function template) | 
| stold	| Convert string to long double (function template) | 




