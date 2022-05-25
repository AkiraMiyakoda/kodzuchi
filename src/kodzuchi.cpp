// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#include "decoder.h"
#include "encoder.h"

KOD_DECODER *kod_decoder_create(KOD_ENCODING encoding)
{
    return new kodzuchi::decoder(encoding);
}

void kod_decoder_destroy(KOD_DECODER *decoder)
{
    delete static_cast<kodzuchi::decoder *>(decoder);
}

KOD_ERROR kod_decoder_decode(KOD_DECODER *decoder, const char *string)
{
    return static_cast<kodzuchi::decoder *>(decoder)->decode(string);
}

const char *kod_decoder_get_result(KOD_DECODER *decoder)
{
    return static_cast<kodzuchi::decoder *>(decoder)->get_result();
}

KOD_ENCODER *kod_encoder_create(KOD_ENCODING encoding)
{
    return new kodzuchi::encoder(encoding);
}

void kod_encoder_destroy(KOD_ENCODER *encoder)
{
    delete static_cast<kodzuchi::encoder *>(encoder);
}

KOD_ERROR kod_encoder_decode(KOD_ENCODER *encoder, const char *string, char default_char)
{
    return static_cast<kodzuchi::encoder *>(encoder)->encode(string, default_char);
}

const char *kod_encoder_get_result(KOD_ENCODER *encoder)
{
    return static_cast<kodzuchi::encoder *>(encoder)->get_result();
}
