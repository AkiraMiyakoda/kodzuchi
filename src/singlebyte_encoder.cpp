// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#include <string>
#include <utfcpp/utf8/checked.h>
#include "singlebyte.h"
#include "singlebyte_encoder.h"

using namespace kodzuchi::singlebyte;

namespace
{
    uint8_t compute_hash1(uint32_t value)
    {
        return value & 0x7f;
    }

    uint8_t compute_hash2(uint32_t value, uint8_t salt)
    {
        return (value ^ (value >> salt)) & 0x7f;
    }

    uint8_t from_utf32(const hashtable *table, uint32_t code_point, uint8_t default_char)
    {
        if (code_point <= 0x7f) {
            return static_cast<uint8_t>(code_point);
        }

        const auto hash1{compute_hash1(code_point)};
        auto hash2{table->encode1[hash1]};
        if (hash2 >= 0x80) {
            hash2 = compute_hash2(code_point, hash1 - 0x80);
        }

        const auto index{table->encode2[hash2]};
        if (code_point != table->decode[index]) {
            return default_char;
        }

        return 0x80 + index;
    }
}

class encoder::impl
{
public:
    const hashtable *hashtable_ {nullptr};
    std::string      result_    {};
};

encoder::encoder(KOD_ENCODING encoding) : impl_(std::make_unique<impl>())
{
    this->impl_->hashtable_ = get_hash_table(encoding);
    if (this->impl_->hashtable_ == nullptr) {
        throw "Invalid encoding.";
    }
}

KOD_ERROR encoder::encode(std::string_view string, char default_char)
{
    std::string result;

    for (auto it{string.cbegin()}; it < string.cend();) {
        const auto code_point{utf8::next(it, string.cend())};
        result += static_cast<char>(from_utf32(this->impl_->hashtable_, code_point, default_char));
    }

    result.swap(this->impl_->result_);

    return KOD_SUCCESS;
}

const char *encoder::get_result() const
{
    return this->impl_->result_.c_str();
}
