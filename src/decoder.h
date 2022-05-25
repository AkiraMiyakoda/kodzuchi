// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef KOD_09E84067_50E8_42EF_A59D_36E4363232AE
#define KOD_09E84067_50E8_42EF_A59D_36E4363232AE

#include <string_view>
#include <boost/noncopyable.hpp>
#include <kodzuchi.h>

typedef struct KOD_DECODER_ {} KOD_DECODER;

namespace kodzuchi
{
    class decoder :
        public KOD_DECODER_,
        private boost::noncopyable
    {
    public:
        decoder() = default;
        virtual ~decoder() = 0;

        virtual KOD_ERROR decode(std::string_view string) = 0;
        virtual const char *get_result() const = 0;
    };
}

#endif // KOD_09E84067_50E8_42EF_A59D_36E4363232AE
