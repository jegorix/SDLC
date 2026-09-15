cmake_minimum_required(VERSION 3.16)

project(HappinessCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)

qt_standard_project_setup()

qt_add_executable(HappinessCalculator
    src/main.cpp
)

target_link_libraries(HappinessCalculator
    PRIVATE
        Qt6::Widgets
        Qt6::Charts
)
