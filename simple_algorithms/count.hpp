#pragma once

#include "node.hpp"
#include "where.hpp"

namespace cxl
{
template<typename T, typename pred>
constexpr auto count(T val, pred p) {
  return count(where(val, p));
}
template <typename T>
constexpr auto count(T val)
{
  if constexpr (!T::is_none)
    return count(typename T::next_t{}) + 1;
  else
    return 0;
}
}