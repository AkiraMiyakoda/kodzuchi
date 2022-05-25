// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef KOD_2FB4628F_2F4C_4416_843B_BB465D58C45E
#define KOD_2FB4628F_2F4C_4416_843B_BB465D58C45E

#include <string_view>
#include <boost/noncopyable.hpp>
#include <kodzuchi.h>

typedef struct KOD_ENCODER_ {} KOD_ENCODER;

namespace kodzuchi
{
    class encoder :
        public KOD_ENCODER_,
        private boost::noncopyable
    {
    public:
        encoder() = default;
        virtual ~encoder() = 0;

        virtual KOD_ERROR encode(std::string_view, char) = 0;
        virtual const char *get_result() const = 0;
    };
}

#endif // KOD_2FB4628F_2F4C_4416_843B_BB465D58C45E
