#include "command_line_arguments/command_line_arguments.h"
#include "filters/filter.h"
#include "bmp/read_from_bmp.h"
#include "bmp/write_to_bmp.h"
#include "matrix.h"

#include <iostream>
#include <exception>

void EditImage(Image& image, const std::vector<std::unique_ptr<Filter>>& filters) {
    for (const std::unique_ptr<Filter>& filter : filters) {
        filter->FilterImage(image);
    }
}

int main(int argc, const char* argv[]) {
    try {
        CommandLineArguments command_line_arguments(argc, argv);
        Image image = ReadFromBmp(command_line_arguments.input_file);
        EditImage(image, command_line_arguments.filters);
        WriteToBmp(image, command_line_arguments.output_file);
    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        return 1;
    }
    return 0;
}
