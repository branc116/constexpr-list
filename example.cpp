#include "constexpr_list.hpp"
using namespace cxl;
#define ca constexpr auto
struct my {
  int a;
  int b;
  constexpr int add() {
    return a + b;
  }
};
constexpr auto empty = empty_list();                   // []

constexpr auto _1 = push_back<1>(empty);               // [1]
constexpr auto _2 = push_back<2>(_1);                  // [1, 2]
constexpr auto _3 = push_back<3>(_2);                  // [1, 2, 3]
constexpr auto pb1 = push_back<2, 3, 4>(empty);        // [2, 3, 4]
constexpr auto pf1 = push_front<2,3,4,1.5,1.2f>(empty);// [1.2f, 1.5, 4, 3, 2]
constexpr auto pb2 = push_back<10>(pf1);               // [4, 3, 2, 10]

constexpr auto f = first(pb2);                         // 4
constexpr auto l = last(pb2);                          // 10
constexpr auto g1 = pb2.template get<0>();             // 4
constexpr auto g2 = pb2.template get<2>();             // 10
constexpr auto g3 = pb2.template get<4444>();          // NoneType

constexpr auto t1 = take</*offset*/1, /*count*/2>(_3); // [2, 3]
constexpr auto t2 = take</*count*/2>(_3);              // [1, 2]

constexpr auto m1 = merge(_3, _3, pf1);                // [1, 1, 1.2, 1.5, 2, 2, 3, 3, 4, 3, 2]
constexpr auto m2 = merge(_3, _3, _2, _1 /*, .... */); // [1, 1, 1, 1, 2, 2, 2, 3, 3]
constexpr auto m3 = merge(empty, empty);               // []

constexpr auto c1 = count(m2);                         // 3 + 3 + 2 + 1 = 9
constexpr auto c2 = count(empty);                      // 0
constexpr auto c3 = count(m2, [](auto i){return i>1;});// 5

constexpr auto r1 = reverse(m2);                       // [3, 3, 2, 2, 2, 1, 1, 1, 1]
constexpr auto r2 = reverse(empty);                    // []

constexpr auto lt = [](auto i, auto j) {return i < j;};
constexpr auto gt = [](auto i, auto j) {return i > j;};

constexpr auto s1 = sort(_1);                          // [1]
constexpr auto s2 = sort(_2);                          // [1, 2]
constexpr auto s3 = sort(_3);                          // [1, 2, 3]
constexpr auto s4 = sort(pb2, lt);                     // [2, 3, 4, 10]
constexpr auto s5 = sort(r1, lt);                      // [1, 1, 1, 1, 2, 2, 2, 3, 3]
constexpr auto s6 = sort(m1, gt);                      // [4, 3, 3, 3, 2, 2, 2, 1.5, 1.2, 1, 1]

constexpr auto w1=where(s5,[](auto i){return i>1;});   // [2, 2, 2, 3, 3]
constexpr auto w2=where(s6,[](auto i){return i>1.3;}); // [4, 3, 3, 3, 2, 2, 2, 1.5]

constexpr auto any1 = any(w1, [](auto i){return i<1;});// false
constexpr auto all1= all(w2,[](auto i){return i>1.3;});// true

constexpr auto map1 = map(_3,[](auto i) {return i*i;});// [1, 4, 9]
constexpr auto n2=map(s6,[](auto i){return (float)i;});// [4.0f, 3.0f, 3.0f, 3.0f, 2.0f, 2.0f, 2.0f, 1.5f, 1.2f, 1.0f, 1.0f]

ca red1=reduce<1>(_3, [](auto a, auto c){return a*c;});// 6
ca red2=reduce<0>(_3, [](auto a, auto c){return a*c;});// 0

constexpr auto avg1 = average(_3);                     // 2
constexpr auto avg2 = average(n2);                     // 2.15454f

constexpr auto sum1 = sum(_3);                         // 6
constexpr auto sum2 = sum(s6);                         // 23.7

struct str1 {
  float i;
  float j;
  constexpr auto xor_em() const noexcept { return (int)i ^ (int)j; }
};
ca n3 = map(n2, [](auto i) {return str1{ i,i * i }; });
ca n4 = map(n3, [](auto i) {return i.xor_em(); });
int main() {
  return 0;
}

//contains, find_index, reduce, sum, average, all, any,
