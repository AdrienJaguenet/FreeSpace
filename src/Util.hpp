#pragma once

#ifndef __cpp_lib_clamp

namespace std
{
template <class T>
constexpr const T& clamp (const T& v, const T&lo, const T& hi)
{
	return v < lo ? lo : v > hi ? hi : v;
}
}

#endif

