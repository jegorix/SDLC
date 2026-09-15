cmake_minimum_required(VERSION 3.16)
project(HappinessCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt") 

# Добавляем компонент Charts
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)

add_executable(HappinessCalculator 
    src/main.cpp
    src/models/HappinessModel.cpp
    src/views/InputDialog.cpp
    src/views/MainWindow.cpp
    src/controllers/HappinessController.cpp
)

target_include_directories(HappinessCalculator PRIVATE src)

# Линуем Qt6::Charts
target_link_libraries(HappinessCalculator PRIVATE Qt6::Widgets Qt6::Charts)