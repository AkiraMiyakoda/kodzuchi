// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef KOD_16B855FB_1933_4E3D_8AAC_7F30D9DBCD50
#define KOD_16B855FB_1933_4E3D_8AAC_7F30D9DBCD50

#include <memory>
#include "decoder.h"

namespace kodzuchi::singlebyte
{
    class decoder : public kodzuchi::decoder
    {
    public:
        decoder(KOD_ENCODING encoding);
        virtual ~decoder() = default;

        virtual KOD_ERROR decode(std::string_view string) override;
        virtual const char *get_result() const override;

    private:
        class impl;
        std::unique_ptr<impl> impl_;
    };
}

#endif // KOD_16B855FB_1933_4E3D_8AAC_7F30D9DBCD50
