cmake_minimum_required(VERSION 2.8.12)

project(RenderStudio LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick QuickControls2 REQUIRED)

set(HEADERS
    ApplicationService.h
    Camera.h
    Project.h
    RenderService.h
    RenderSettings.h
)

set(SOURCES
    main.cpp
    ApplicationService.cpp
    Camera.cpp
    Project.cpp
    RenderService.cpp
    RenderSettings.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} "qml.qrc")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::QuickControls2)
