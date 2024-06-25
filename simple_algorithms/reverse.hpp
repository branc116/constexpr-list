#pragma once
#include "node.hpp"
#include "push_front.hpp"
namespace cxl {
namespace impl {
  template<typename T, typename tmp>
  constexpr auto reverse_impl(T v, tmp a) {
    if constexpr (T::is_none)
    {
      return a;
    }
    else {
      auto next = push_front<T::node_v>(a);
      typename T::next_t my_n{};
      auto rev = reverse_impl(my_n, next);
      return rev;
    }
  }
};

template<typename T>
constexpr auto reverse(T v) {
  return impl::reverse_impl(v, NoneType{});
}
}