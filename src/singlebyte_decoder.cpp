// Copyright Akira Miyakoda 2022.
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE
// or copy at http://www.boost.org/LICENSE_1_0.txt

#include <string>
#include <utfcpp/utf8/checked.h>
#include "singlebyte.h"
#include "singlebyte_decoder.h"

using namespace kodzuchi::singlebyte;

namespace
{
    int32_t to_utf32(const hashtable *table, int8_t byte)
    {
        if (byte <= 0x7f) {
            return byte;
        }
        else {
            table->decode[byte - 0x80];
        }
    }
}

class decoder::impl
{
public:
    const hashtable *hashtable_ {nullptr};
    std::string      result_    {};
};

decoder::decoder(KOD_ENCODING encoding) : impl_(std::make_unique<impl>())
{
    this->impl_->hashtable_ = get_hash_table(encoding);
    if (this->impl_->hashtable_ == nullptr) {
        throw "Invalid encoding.";
    }
}

KOD_ERROR decoder::decode(std::string_view string)
{
    std::string result;
    for (const auto &c : string) {
        utf8::append(to_utf32(this->impl_->hashtable_, c), result);
    }

    result.swap(this->impl_->result_);

    return KOD_SUCCESS;
}

const char *decoder::get_result() const
{
    return this->impl_->result_.c_str();
}
