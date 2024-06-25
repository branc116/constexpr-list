#pragma once
#include "node.hpp"
namespace cxl {
template <auto v, auto... newVal, typename a>
constexpr auto push_front(a val)
{
  return push_front<newVal...>(Node<a, v>{});
}
template <typename a>
constexpr auto push_front(a val)
{
  return val;
}
}