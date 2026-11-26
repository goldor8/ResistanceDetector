cmake_minimum_required(VERSION 3.16)
project(resistor_reader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs highgui)

file(GLOB_RECURSE RESISTOR_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# main.cpp ne fait pas partie de la bibliothèque : on le retire
list(REMOVE_ITEM RESISTOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# add_library(resistor_core ${RESISTOR_SOURCES})
# add_library(resistor_core
#     src/ImageLoader.cpp src/Preprocessor.cpp src/ResistorLocator.cpp
#     src/BandDetector.cpp src/ColorClassifier.cpp src/ResistorDecoder.cpp
#     src/Pipeline.cpp)
# target_include_directories(resistor_core PUBLIC include)
# target_link_libraries(resistor_core PUBLIC ${OpenCV_LIBS})

add_executable(resistor-reader src/main.cpp)
target_link_libraries(resistor-reader PUBLIC ${OpenCV_LIBS})
# target_link_libraries(resistor-reader PRIVATE resistor_core)

enable_testing()
