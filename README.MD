#### These code are trying to find a way to reduce the STL build time

### Use `std::visit()` and `std::memcmp()` directly.
```shell
$ time g++ -std=c++17 compareInst.cpp
g++ -std=c++17 compareInst.cpp  7.91s user 0.43s system 97% cpu 8.553 total
$ /usr/bin/time -v g++ -std=c++17 compareInst.cpp
        Command being timed: "g++ -std=c++17 compareInst.cpp"
        User time (seconds): 7.78
        System time (seconds): 0.50
        Percent of CPU this job got: 97%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:08.51
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 854264
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 20
        Minor (reclaiming a frame) page faults: 259460
        Voluntary context switches: 2991
        Involuntary context switches: 12
        Swaps: 0
        File system inputs: 2336
        File system outputs: 154744
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0
```

### Overload `operate==` with `std::memcmp()` 
```shell
$ time g++ -std=c++17 overloadEq.cpp
g++ -std=c++17 overloadEq.cpp  0.15s user 0.03s system 66% cpu 0.261 total
$ /usr/bin/time -v g++ -std=c++17 overloadEq.cpp
        Command being timed: "g++ -std=c++17 overloadEq.cpp"
        User time (seconds): 0.14
        System time (seconds): 0.02
        Percent of CPU this job got: 64%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.26
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 59300
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 0
        Minor (reclaiming a frame) page faults: 16361
        Voluntary context switches: 608
        Involuntary context switches: 1
        Swaps: 0
        File system inputs: 0
        File system outputs: 16
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0
```

We can see that the STL build time is reduced from 8.553s to 0.261s after overloading `operator==` with `std::memcmp()`.

