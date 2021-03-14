#pragma once
#include "node.hpp"
#include "simple_algorithms/merge.hpp"
#include "simple_algorithms/count.hpp"
#include "simple_algorithms/take.hpp"
namespace cxl {
template<typename T>
constexpr auto sort(T val) {
  constexpr auto n = count(val);
  constexpr auto l_n = n >> 1;
  constexpr auto r_n = n - l_n;
  auto l = take<l_n>(val);
  auto r = take<l_n, r_n>(val);
  auto s_l = sort(l);
  auto s_r = sort(r);
  return merge(s_l, s_r);
}
template<int i, int j>
constexpr auto sort(Node<Node<NoneType, i>, j> val) {
  if constexpr (i < j) {
    return Node<Node<NoneType, j>, i>{};
  }
  else {
    return val;
  }
}
template<int i>
constexpr auto sort(Node<NoneType, i> val) {
  return val;
}
template<>
constexpr auto sort(NoneType val) {
  return val;
}
}