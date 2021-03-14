# Constexpr list with some algorithms
Header only constexpr cpp library for interger list manipulations.

## Features

* Create lists in compile time
* Add elements dynamically in compile time to your lists
* Preform basic operations over your list
  * get number of elements
  * merge 2 or more lists into one
  * reverse list
  * take sub list of lists
  * sort elements of the list
  * everything in compile time

## Example

example.cpp:

```cpp
#include "constexpr_list.hpp"
using namespace cxl;

constexpr auto empty = empty_list();                   // []

constexpr auto _1 = push_back<1>(empty);               // [1]
constexpr auto _2 = push_back<2>(_1);                  // [1, 2]
constexpr auto _3 = push_back<3>(_2);                  // [1, 2, 3]
constexpr auto pb1 = push_back<2, 3, 4>(empty);        // [2, 3, 4]
constexpr auto pf1 = push_front<2, 3, 4>(empty);       // [4, 3, 2]
constexpr auto pb2 = push_back<10>(pf1);               // [4, 3, 2, 10]

constexpr auto f = first(pb2);                         // 4
constexpr auto l = last(pb2);                          // 10
constexpr auto g1 = pb2.get<0>();                      // 4
constexpr auto g2 = pb2.get<3>();                      // 10
constexpr auto g3 = pb2.get<4444>();                   // NoneType

constexpr auto t1 = take</*offset*/1, /*count*/2>(_3); // [2, 3]
constexpr auto t2 = take</*count*/2>(_3);              // [1, 2]

constexpr auto m1 = merge(_3, _3);                     // [1, 1, 2, 2, 3, 3]
constexpr auto m2 = merge(_3, _3, _2, _1 /*, .... */); // [1, 1, 1, 1, 2, 2, 2, 3, 3]
constexpr auto m3 = merge(empty, empty);               // []

constexpr auto c1 = count(m2);                         // 3 + 3 + 2 + 1 = 9
constexpr auto c2 = count(empty);                      // 0

constexpr auto r1 = reverse(m2);                       // [3, 3, 2, 2, 2, 1, 1, 1, 1]
constexpr auto r2 = reverse(empty);                    // []

constexpr auto s1 = sort(_1);                          // [1]
constexpr auto s2 = sort(_2);                          // [1, 2]
constexpr auto s3 = sort(_3);                          // [1, 2, 3]
constexpr auto s4 = sort(pb2);                         // [2, 3, 4, 10]
constexpr auto s5 = sort(r1);                          // [1, 1, 1, 1, 2, 2, 2, 3, 3]
```
## Use cases
IDK.

## How to build

You don't build this, you include this headers into you cpp file and you build your cpp file.

## Y?

Y not?