#pragma once
#include "node.hpp"
#include "simple_algorithms/merge.hpp"
#include "simple_algorithms/count.hpp"
#include "simple_algorithms/take.hpp"
namespace cxl {
template<typename T>
constexpr auto sort(T val) {
  return sort(val, [](auto i, auto j) { return i < j; });
}
template<typename T, typename pred>
constexpr auto sort(T val, pred p) {
  constexpr auto n = count(val);
  constexpr auto l_n = n >> 1;
  constexpr auto r_n = n - l_n;
  return merge(p,
    sort(take<l_n>(val), p),
    sort(take<l_n, r_n>(val), p)
  );
}
template<auto i, auto j, typename pred>
constexpr auto sort(Node<Node<NoneType, i>, j> val, pred p) {
  if constexpr (p(i, j)) {
    return Node<Node<NoneType, j>, i>{};
  }
  else {
    return val;
  }
}
template<auto i, typename pred>
constexpr auto sort(Node<NoneType, i> val, pred p) {
  return val;
}
template<typename pred>
constexpr auto sort(NoneType val, pred p) {
  return val;
}
}