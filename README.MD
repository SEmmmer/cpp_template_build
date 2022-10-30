#### These code are trying to find a way to reduce the STL build time

### Use `std::visit()` and `std::memcmp()` directly.
```shell
$ time g++ -std=c++17 compareInst.cpp
g++ -std=c++17 compareInst.cpp  7.91s user 0.43s system 97% cpu 8.553 total
```

### Overload `operate==` with `std::memcmp()` 
```shell
$ time g++ -std=c++17 overloadEq.cpp
g++ -std=c++17 overloadEq.cpp  0.15s user 0.03s system 66% cpu 0.261 total
```

We can see that the STL build time is reduced from 8.553s to 0.261s after overloading `operator==` with `std::memcmp()`.

