#pragma once
#include "node.hpp"
namespace cxl {
namespace impl {
template <int v, typename T>
constexpr auto push_back_impl(T val)
{
  if constexpr (T::is_none) {
    return Node<NoneType, v>{};
  }
  else {
    typename T::next_t next{};
    auto n = impl::push_back_impl<v>(next);
    return Node<decltype(n), T::node_v>{};
  }
}
}
template <int v, int... rest, typename T>
constexpr auto push_back(T val)
{
  auto a = impl::push_back_impl<v>(val);
  auto b = push_back<rest...>(a);
  return b;
}
template <typename T>
constexpr auto push_back(T val)
{
  return val;
}
}