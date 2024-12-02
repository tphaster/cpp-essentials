/**
 *        File:  bit_backport.hpp
 * Description:  Backport of useful functions from <bit> header from new C++
 *               standard revisions.
 *         Ref:  https://stackoverflow.com/a/3279550/3157524
 *
 *      Author:  Tomasz Pieczerak <tphaster AT gmail.com>
 */

#ifndef __CPP_ESSENTIALS_BIT_BACKPORTS_HPP
#define __CPP_ESSENTIALS_BIT_BACKPORTS_HPP

#include <cstring>
#include <type_traits>

/// @brief Obtain a value of type `To` by reinterpreting the object
/// representation of `From`.
///
/// Every bit in the value representation of the returned `To` object is equal
/// to the corresponding bit in the object representation of `From`. The values
/// of padding bits in the returned `To` object are unspecified.
///
/// @param from The source of bits for the return value.
/// @return An object of type `To` whose value representation is as described
/// above.
// clang-format off
template <typename To,
          typename From,
          typename = std::enable_if_t<
              (sizeof(To) == sizeof(From)) &&
              std::is_trivially_copyable_v<From> &&
              std::is_trivially_copyable_v<To>>>
// clang-format on
To bit_cast(const From &src) noexcept {
  To dst;
  std::memcpy(&dst, &src, sizeof(To));
  return dst;
}

#endif // __CPP_ESSENTIALS_BIT_BACKPORTS_HPP
