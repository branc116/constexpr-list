#pragma once
#include "node.hpp"
namespace cxl {
template <int v, int... newVal, typename a>
constexpr auto push_front(a val)
{
  auto tmp = Node<a, v>{};
  return push_front<newVal...>(tmp);
}
template <typename a>
constexpr auto push_front(a val)
{
  return val;
}
}