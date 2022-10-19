#pragma once

#include <string_view>
#include <vector>

#include "../filters/filter.h"

class CommandLineArguments {
public:
    CommandLineArguments(int argc, const char* argv[]);

    std::string_view input_file;
    std::string_view output_file;
    std::vector<std::unique_ptr<Filter>> filters;
};
