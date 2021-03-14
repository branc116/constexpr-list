#pragma once
#include "node.hpp"
namespace cxl {
template <int offset, int count, typename T>
constexpr auto take(T val)
{
  if constexpr (offset > 0) {
    typename T::next_t tmp{};
    return take<offset - 1, count>(tmp);
  }
  else
    return take<count>(val);
}
template <int count, typename T>
constexpr auto take(T val)
{
  if constexpr (count > 0) {
    typename T::next_t tmp{};
    return Node<decltype(take<count - 1>(tmp)), T::node_v>{};
  }
  else
    return NoneType{};
}
template <int offset, int count>
constexpr auto take(NoneType val)
{
  return val;
}
template <int count>
constexpr auto take(NoneType val)
{
  return val;
}
}