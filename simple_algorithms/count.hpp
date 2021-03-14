#pragma once

#include "node.hpp"
namespace cxl
{
template <typename T>
constexpr auto count(T val)
{
  if constexpr (!T::is_none)
    return count(typename T::next_t{}) + 1;
  else
    return 0;
}
}