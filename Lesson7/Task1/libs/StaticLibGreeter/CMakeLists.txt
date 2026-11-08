add_library(StaticLibGreeter STATIC src/Greeter.cpp)

target_include_directories(StaticLibGreeter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)