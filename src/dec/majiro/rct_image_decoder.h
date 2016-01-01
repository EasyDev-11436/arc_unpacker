#pragma once

#include "dec/base_image_decoder.h"

namespace au {
namespace dec {
namespace majiro {

    class RctImageDecoder final : public BaseImageDecoder
    {
    public:
        RctImageDecoder();
        ~RctImageDecoder();
        void register_cli_options(ArgParser &arg_parser) const override;
        void parse_cli_options(const ArgParser &arg_parser) override;
        void set_key(const bstr &key);

    protected:
        bool is_recognized_impl(io::File &input_file) const override;
        res::Image decode_impl(
            const Logger &logger, io::File &input_file) const override;

    private:
        struct Priv;
        std::unique_ptr<Priv> p;
    };

} } }