cmake_minimum_required(VERSION 3.14)
project(testUnit CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Скачиваем саму библиотеку GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Включаем поддержку тестирования в CMake
enable_testing()


# Создаем исполняемый файл с тестами
add_executable(run_tests tests/NativeUnitTest.cpp)
target_link_libraries(run_tests PRIVATE GTest::gtest_main)

# Подключаем встроенный модуль CMake и регистрируем тесты
include(GoogleTest)
gtest_discover_tests(run_tests)