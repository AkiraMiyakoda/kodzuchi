// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef KOD_588F7DD4_C4A0_4DB0_A2E6_6CB20333CD8B
#define KOD_588F7DD4_C4A0_4DB0_A2E6_6CB20333CD8B

#include <cstdint>
#include <array>

namespace kodzuchi::singlebyte
{
    struct hashtable
    {
        std::array<uint16_t, 128> decode;
        std::array<uint8_t,  128> encode1;
        std::array<uint8_t,  128> encode2;
    };
}

#endif // KOD_588F7DD4_C4A0_4DB0_A2E6_6CB20333CD8B
