#pragma once
#include "../node.hpp"

namespace cxl
{
  template<auto zero, typename T, typename transform>
  constexpr auto reduce(T val, transform t) {
    constexpr auto a = t(zero, T::node_v);
    typename T::next_t n{};
    return reduce<a>(n, t);
  }
  template<auto zero, typename transform>
  constexpr auto reduce(NoneType val, transform t) {
    return zero;
  }
}
