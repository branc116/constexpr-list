#pragma once
#include "../node.hpp"
namespace cxl {
  template <typename T, typename pred>
  constexpr auto where(T val, pred p) {
    typename T::next_t n{};
    if constexpr (p(T::node_v)) {
      return Node<decltype(where(n, p)), T::node_v>{};
    }
    else {
      return where(n, p);
    }
  }
  template<typename pred>
  constexpr auto where(NoneType val, pred p) {
    return val;
  }
}