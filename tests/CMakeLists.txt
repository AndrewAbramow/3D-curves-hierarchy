# CMakeList.txt: проект CMake для 3DCurvesHierarchy; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.17)

project ("tests_3DCurvesHierarchy")

# Add Google Test library
include(FetchContent)
FetchContent_Declare(
googletest
URL
https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#set(gtest_disable_pthreads on)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(CMAKE_CXX_STANDARD 17)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_compile_definitions(TESTS)

add_executable (tests_3DCurvesHierarchy "tests.cpp")

target_include_directories(tests_3DCurvesHierarchy PRIVATE "../include")
target_link_libraries(tests_3DCurvesHierarchy PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(tests_3DCurvesHierarchy)

