cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(image_processor
        image_processor.cpp
        filters/filter.cpp filters/filter.h
        filters/crop.cpp filters/crop.h
        filters/grayscale.cpp filters/grayscale.h
        filters/negative.cpp filters/negative.h
        filters/sharpening.cpp filters/sharpening.h
        filters/convolution.cpp filters/convolution.h
        filters/edge_detection.cpp filters/edge_detection.h
        filters/gaussian_blur.cpp filters/gaussian_blur.h
        filters/bloom_effect.cpp filters/bloom_effect.h
        filters/median_filter.cpp filters/median_filter.h
        command_line_arguments/command_line_arguments.cpp command_line_arguments/command_line_arguments.h
        matrix.h
        rgb/rgb.cpp rgb/rgb.h
        bmp/bmp_header.cpp bmp/bmp_header.h
        bmp/read_from_bmp.cpp bmp/read_from_bmp.h
        bmp/write_to_bmp.cpp bmp/write_to_bmp.h)
