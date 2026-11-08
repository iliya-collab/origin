add_library(DynamicLibLeaver SHARED src/Leaver.cpp)

target_compile_definitions(DynamicLibLeaver PRIVATE BUILDING_LEAVER_DLL)

target_include_directories(DynamicLibLeaver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)