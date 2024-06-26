#pragma once
#include "../node.hpp"
#include "reduce.hpp"
namespace cxl {
  namespace impl {
    template<typename t>
    struct avg_reduce {
      t sum;
      unsigned long long count;
    };
  }
  template<typename T>
  constexpr auto average(T var) {
    typename T::next_t t{};
    constexpr auto a = cxl::reduce<impl::avg_reduce<typename T::node_t>{T::node_v, 1ul}>(t, [](auto acc, auto cur) {
      return impl::avg_reduce<typename T::node_t>{ acc.sum + cur, acc.count + 1 };
    });
    return static_cast<T::node_t>(a.sum / a.count);
  }
  constexpr auto average(NoneType var) {
    return var;
  }
}
