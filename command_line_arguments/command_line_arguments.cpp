#include "command_line_arguments.h"

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

CommandLineArguments::CommandLineArguments(int argc, const char* argv[]) {
    if (argc == 1) {
        std::cout << "Enter the path to the input file, then the path to the output file, then the list of filters "
                     "(filters are separated by space).\n"
                     "The filter must start with symbol \"-\", then follows the filter name, then a space,"
                     "then the filter parameters (parameters are separated by space).\n"
                     "Filter list:\n"
                     "Crop\n"
                     "name: crop\n"
                     "parameters: two positive integers\n"

                     "Grayscale\n"
                     "name: gs\n"
                     "parameters: none\n"

                     "Negative\n"
                     "name: neg\n"
                     "parameters: none\n"

                     "Sharpening\n"
                     "name: sharp\n"
                     "parameters: none\n"

                     "Edge Detection\n"
                     "name: edge\n"
                     "parameters: number from 0 to 1\n"

                     "Gaussian Blur\n"
                     "name: blur\n"
                     "parameters: non-negative number\n"

                     "Bloom Effect\n"
                     "name: bloom\n"
                     "parameters: number from 0 to 1\n"

                     "Median Filter\n"
                     "name: med\n"
                     "parameters: non-negative integer\n";
        std::exit(0);
    } else if (argc == 2) {
        throw std::runtime_error("Enter paths to input and output files");
    }
    input_file = argv[1];
    output_file = argv[2];
    std::vector<const std::string> current_filter;
    for (int i = 3; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (!current_filter.empty()) {
                filters.push_back(Filter::CreateFilter(current_filter));
            }
            current_filter.clear();
        }
        current_filter.push_back(argv[i]);
    }
    if (!current_filter.empty()) {
        filters.push_back(Filter::CreateFilter(current_filter));
    }
}
