### for colon (element_declaration)

```
for (const auto& kv : myMap) {
    std::cout << kv.first << " has value " << kv.second << std::endl;
}
```

### Iterator

```
std::map<char,int> mymap;

mymap['b'] = 100;
mymap['a'] = 200;
mymap['c'] = 300;

// show content:
for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
  std::cout << it->first << " => " << it->second << '\n';
}
```

### add value
```
std::map<char,int> mymap;

mymap.emplace('x',100);
mymap.emplace('y',200);
mymap.emplace('z',100);
```

```
std::map<char,int> mymap;

mymap.insert ( std::pair<char,int>('a',100) );
mymap.insert ( std::pair<char,int>('z',200) );
```

### erase

```
it=mymap.find('b');
mymap.erase (it);                   // erasing by iterator

mymap.erase ('c');                  // erasing by key

it=mymap.find ('e');
mymap.erase ( it, mymap.end() );    // erasing by range
```

### lower_bound & upper_bound

```
std::map<char,int>::iterator itlow,itup;

mymap['a']=20;
mymap['b']=40;
mymap['c']=60;
mymap['d']=80;
mymap['e']=100;

itlow=mymap.lower_bound ('b');  // itlow points to b
itup=mymap.upper_bound ('d');   // itup points to e (not d!)

mymap.erase(itlow,itup);        // erases [itlow,itup)
```
