#pragma once
namespace cxl {
struct NoneType
{
  constexpr const static bool is_none = true;
  template <int i>
  constexpr auto get()
  {
    return NoneType{};
  }
};
template <typename next, int val>
struct Node
{
  constexpr const static bool is_none = false;
  using next_t = next;
  constexpr const static int node_v = val;
  template <int i>
  constexpr auto get() const noexcept
  {
    if constexpr (i <= 0)
      return node_v;
    else {
      next tmp{};
      return tmp.get<i - 1>();
    }
  }
};

template <typename T>
constexpr auto first(T v)
{
  return T::node_v;
}
template <typename T, int v>
constexpr auto last(Node<T, v> val)
{
  return last(T{});
}
template <int v>
constexpr auto last(Node<NoneType, v> val)
{
  return v;
}
constexpr auto empty_list()
{
  return NoneType{};
}
}