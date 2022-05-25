# Copyright Akira Miyakoda 2022.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE
# or copy at http://www.boost.org/LICENSE_1_0.txt

set(KODZUCHI_SRC
    kodzuchi.cpp
    singlebyte.cpp
    singlebyte_decoder.cpp
)

add_library(kodzuchi ${KODZUCHI_SRC})
target_include_directories(kodzuchi
    PRIVATE ${Boost_INCLUDE_DIR}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${PROJECT_SOURCE_DIR}/3rdparty
)
