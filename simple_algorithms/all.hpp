#pragma once
#include "../node.hpp"

namespace cxl
{
  template<typename T, typename pred>
  constexpr auto all(T val, pred p) {
    if constexpr (p(T::node_v)) {
      typename T::next_t n{};
      return all(n, p);
    }else 
      return false;
  }
  template<typename pred>
  constexpr auto all(NoneType val, pred p) {
    return true;
  }
}
