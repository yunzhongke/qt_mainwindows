cmake_minimum_required(VERSION 3.0)

project(mainwidows)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "/home/yunzhongke/work/Qt5.6.2/5.6/gcc_64/lib/cmake/Qt5Widgets/Qt5WidgetsConfig.cmake")

aux_source_directory(. SRC_LIST)

find_package(Qt5Widgets)
if(Qt5Widgets_FOUND)
    message(STATUS ${Qt5Widgets_VERSION_STRING})
endif()

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})
