#pragma once
#include "node.hpp"
namespace cxl {
namespace impl {
template <auto v, typename T>
constexpr auto push_back_impl(T val)
{
  if constexpr (T::is_none) {
    return Node<NoneType, v>{};
  }
  else {
    typename T::next_t next{};
    return Node<decltype(impl::push_back_impl<v>(next)), T::node_v>{};
  }
}
}
template <auto v, auto... rest, typename T>
constexpr auto push_back(T val)
{
  auto b = push_back<rest...>(impl::push_back_impl<v>(val));
  return b;
}
template <typename T>
constexpr auto push_back(T val)
{
  return val;
}
}