// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#include "singlebyte.h"
#include "tables/singlebyte/ibm866.h"
#include "tables/singlebyte/iso_8859_10.h"
#include "tables/singlebyte/iso_8859_13.h"
#include "tables/singlebyte/iso_8859_14.h"
#include "tables/singlebyte/iso_8859_15.h"
#include "tables/singlebyte/iso_8859_16.h"
#include "tables/singlebyte/iso_8859_2.h"
#include "tables/singlebyte/iso_8859_3.h"
#include "tables/singlebyte/iso_8859_4.h"
#include "tables/singlebyte/iso_8859_5.h"
#include "tables/singlebyte/iso_8859_6.h"
#include "tables/singlebyte/iso_8859_7.h"
#include "tables/singlebyte/iso_8859_8.h"
#include "tables/singlebyte/koi8_r.h"
#include "tables/singlebyte/koi8_u.h"
#include "tables/singlebyte/macintosh.h"
#include "tables/singlebyte/windows_1250.h"
#include "tables/singlebyte/windows_1251.h"
#include "tables/singlebyte/windows_1252.h"
#include "tables/singlebyte/windows_1253.h"
#include "tables/singlebyte/windows_1254.h"
#include "tables/singlebyte/windows_1255.h"
#include "tables/singlebyte/windows_1256.h"
#include "tables/singlebyte/windows_1257.h"
#include "tables/singlebyte/windows_1258.h"
#include "tables/singlebyte/windows_874.h"
#include "tables/singlebyte/x_mac_cyrillic.h"

using namespace kodzuchi::singlebyte;

const hashtable *get_hash_table(KOD_ENCODING encoding)
{
    switch (encoding)
    {
    case KOD_IBM866:
        return &ibm866_table;
    case KOD_ISO_8859_2:
        return &iso_8859_2_table;
    case KOD_ISO_8859_3:
        return &iso_8859_3_table;
    case KOD_ISO_8859_4:
        return &iso_8859_4_table;
    case KOD_ISO_8859_5:
        return &iso_8859_5_table;
    case KOD_ISO_8859_6:
        return &iso_8859_6_table;
    case KOD_ISO_8859_7:
        return &iso_8859_7_table;
    case KOD_ISO_8859_8:
        return &iso_8859_8_table;
    case KOD_ISO_8859_8_I:
        return &iso_8859_8_table;
    case KOD_ISO_8859_10:
        return &iso_8859_10_table;
    case KOD_ISO_8859_13:
        return &iso_8859_13_table;
    case KOD_ISO_8859_14:
        return &iso_8859_14_table;
    case KOD_ISO_8859_15:
        return &iso_8859_15_table;
    case KOD_ISO_8859_16:
        return &iso_8859_16_table;
    case KOD_KOI8_R:
        return &koi8_r_table;
    case KOD_KOI8_U:
        return &koi8_u_table;
    case KOD_MACINTOSH:
        return &macintosh_table;
    case KOD_WINDOWS_874:
        return &windows_874_table;
    case KOD_WINDOWS_1250:
        return &windows_1250_table;
    case KOD_WINDOWS_1251:
        return &windows_1251_table;
    case KOD_WINDOWS_1252:
        return &windows_1252_table;
    case KOD_WINDOWS_1253:
        return &windows_1253_table;
    case KOD_WINDOWS_1254:
        return &windows_1254_table;
    case KOD_WINDOWS_1255:
        return &windows_1255_table;
    case KOD_WINDOWS_1256:
        return &windows_1256_table;
    case KOD_WINDOWS_1257:
        return &windows_1257_table;
    case KOD_WINDOWS_1258:
        return &windows_1258_table;
    case KOD_X_MAC_CYRILLIC:
        return &x_mac_cyrillic_table;
    default:
        return nullptr;
    }
}
