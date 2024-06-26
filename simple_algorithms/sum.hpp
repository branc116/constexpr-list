#pragma once
#include "../node.hpp"
#include "reduce.hpp"
namespace cxl {
  template<typename T>
  constexpr auto sum(T var) {
    typename T::next_t t{};
    constexpr auto a = cxl::reduce<T::node_v>(t, [](auto acc, auto cur) {
      return acc + cur;
    });
    return a;
  }
  constexpr auto sum(NoneType var) {
    return var;
  }
}
