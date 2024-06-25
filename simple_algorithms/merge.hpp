#pragma once
#include "node.hpp"
#include <type_traits>
namespace cxl {

template<typename T>
concept compare = requires (T t) { t(0, 0); };
template <typename n1, typename n2, typename... rest>
constexpr auto merge(n1 v1, n2 v2, rest... r) {
  return merge([](auto i, auto j) {return i < j; }, v1, v2, r...);
}
template <compare pred, typename n1, typename n2, typename... rest>
constexpr auto merge(pred p, n1 v1, n2 v2, rest... r) {
  return merge(p, merge(p, v1, v2), r...);
}
template <compare pred, typename n1, typename n2>
constexpr auto merge(pred p, n1 v1, n2 v2)
{
  if constexpr (p(n1::node_v, n2::node_v))
  {
    typename n1::next_t tmp{};
    return Node<decltype(merge(p, tmp, v2)), n1::node_v>{};
  }
  else
  {
    typename n2::next_t tmp{};
    return Node<decltype(merge(p, v1, tmp)), n2::node_v>{};
  }
}
template <compare pred, typename n2>
requires std::negation_v<std::is_same<n2, NoneType>> constexpr auto merge(pred p, NoneType nt, n2 v2)
{
  return v2;
}
template <compare pred, typename n1>
constexpr auto merge(pred p, n1 v1, NoneType n2)
{
  return v1;
}
}