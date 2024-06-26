#pragma once
#include "../node.hpp"

namespace cxl
{
  template<typename T, typename transform>
  constexpr auto map(T val, transform t) {
    constexpr auto a = t(T::node_v);
    typename T::next_t n{};
    return Node<decltype(map(n, t)), a>{};
  }
  template<typename transform>
  constexpr auto map(NoneType val, transform t) {
    return val;
  }
}
