// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef KOD_965940AE_8030_414E_AF61_C5D2177A4A1D
#define KOD_965940AE_8030_414E_AF61_C5D2177A4A1D

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    KOD_SUCCESS             = 0,
    KOD_INVALID_CODE_POINT  = 1,
    KOD_INVALID_UTF8        = 2,
} KOD_ERROR;

typedef enum {
    KOD_IBM866         = 0,
    KOD_ISO_8859_2     = 1,
    KOD_ISO_8859_3     = 2,
    KOD_ISO_8859_4     = 3,
    KOD_ISO_8859_5     = 4,
    KOD_ISO_8859_6     = 5,
    KOD_ISO_8859_7     = 6,
    KOD_ISO_8859_8     = 7,
    KOD_ISO_8859_8_I   = 8,
    KOD_ISO_8859_10    = 9,
    KOD_ISO_8859_13    = 10,
    KOD_ISO_8859_14    = 11,
    KOD_ISO_8859_15    = 12,
    KOD_ISO_8859_16    = 13,
    KOD_KOI8_R         = 14,
    KOD_KOI8_U         = 15,
    KOD_MACINTOSH      = 16,
    KOD_WINDOWS_874    = 17,
    KOD_WINDOWS_1250   = 18,
    KOD_WINDOWS_1251   = 19,
    KOD_WINDOWS_1252   = 20,
    KOD_WINDOWS_1253   = 21,
    KOD_WINDOWS_1254   = 22,
    KOD_WINDOWS_1255   = 23,
    KOD_WINDOWS_1256   = 24,
    KOD_WINDOWS_1257   = 25,
    KOD_WINDOWS_1258   = 26,
    KOD_X_MAC_CYRILLIC = 27,
} KOD_ENCODING;

typedef struct KOD_DECODER_ KOD_DECODER;
typedef struct KOD_ENCODER_ KOD_ENCODER;

KOD_DECODER *kod_decoder_create(KOD_ENCODING encoding);
void         kod_decoder_destroy(KOD_DECODER *decoder);
KOD_ERROR    kod_decoder_decode(KOD_DECODER *decoder, const char *string);
const char  *kod_decoder_get_result(KOD_DECODER *decoder);

KOD_ENCODER *kod_encoder_create(KOD_ENCODING encoding);
void         kod_encoder_destroy(KOD_ENCODER *encoder);
KOD_ERROR    kod_encoder_encode(KOD_ENCODER *encoder, const char *string, char default_char);
const char  *kod_encoder_get_result(KOD_ENCODER *encoder);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // KOD_965940AE_8030_414E_AF61_C5D2177A4A1D
