#pragma once
#include "node.hpp"
#include <type_traits>
namespace cxl {
template <typename n1, typename n2, typename... rest>
constexpr auto merge(n1 v1, n2 v2, rest... r) {
  auto l = merge(v1, v2);
  return merge(l, r...);
}
template <typename n1, typename n2>
constexpr auto merge(n1 v1, n2 v2)
{
  if constexpr (n1::node_v < n2::node_v)
  {
    typename n1::next_t tmp{};
    auto next = merge(tmp, v2);
    return Node<decltype(next), n1::node_v>{};
  }
  else
  {
    typename n2::next_t tmp{};
    auto next = merge(v1, tmp);
    return Node<decltype(next), n2::node_v>{};
  }
}
template <typename n2>
requires std::negation_v<std::is_same<n2, NoneType>> constexpr auto merge(NoneType nt, n2 v2)
{
  return v2;
}
template <typename n1>
constexpr auto merge(n1 v1, NoneType n2)
{
  return v1;
}
}