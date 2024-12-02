/**
 *        File:  utility_backport.hpp
 * Description:  Backport of useful functions from <utility> header from new C++
 *               standard revisions.
 *         Ref:  https://stackoverflow.com/a/3279550/3157524
 *
 *      Author:  Tomasz Pieczerak <tphaster AT gmail.com>
 */

#ifndef __CPP_ESSENTIALS_UTILITY_BACKPORT_HPP
#define __CPP_ESSENTIALS_UTILITY_BACKPORT_HPP

#include <type_traits>

#if __cplusplus >= 202002L
#error std::to_underlying is available in C++20, remove this implementation \
       and replace all uses with std::to_underlying.
#endif

/// @brief Converts an enumeration to its underlying type.
///
/// @param e Enumeration value to convert.
/// @return The integer value of the underlying type of `Enum`, converted from
///         `e`.
template <typename E>
constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept {
  return static_cast<typename std::underlying_type<E>::type>(e);
}

#endif // __CPP_ESSENTIALS_UTILITY_BACKPORT_HPP
