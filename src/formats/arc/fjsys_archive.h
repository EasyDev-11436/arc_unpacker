#ifndef FORMATS_ARC_FJSYS_ARCHIVE
#define FORMATS_ARC_FJSYS_ARCHIVE
#include "formats/archive.h"

class FjsysArchive final : public Archive
{
public:
    FjsysArchive();
    ~FjsysArchive();
    void add_cli_help(ArgParser &arg_parser) const override;
    void parse_cli_options(ArgParser &arg_parser) override;
    void unpack_internal(IO &arc_io, OutputFiles &output_files) const override;
private:
    struct Context;
    Context *context;
};

#endif