#ifndef KOD_65ED8607_0C51_4899_8DB5_062CFC3E7D49
#define KOD_65ED8607_0C51_4899_8DB5_062CFC3E7D49

#include <memory>
#include "encoder.h"

namespace kodzuchi::singlebyte
{
    class encoder : public kodzuchi::encoder
    {
    public:
        encoder(KOD_ENCODING encoding);
        virtual ~encoder() = default;

        virtual KOD_ERROR encode(std::string_view string, char default_char) override;
        virtual const char *get_result() const override;

    private:
        class impl;
        std::unique_ptr<impl> impl_;
    };
}

#endif // KOD_65ED8607_0C51_4899_8DB5_062CFC3E7D49
