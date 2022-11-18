# CMakeList.txt: проект CMake для 3DCurvesHierarchy; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.17)

project ("3DCurvesHierarchy")

# Добавьте источник в исполняемый файл этого проекта.
add_subdirectory(tests)
add_executable (3DCurvesHierarchy "src/3DCurvesHierarchy.cpp")
target_include_directories(3DCurvesHierarchy PRIVATE "include")
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
