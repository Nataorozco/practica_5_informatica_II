cmake_minimum_required(VERSION 3.16)
project(juego LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(juego src/main.cpp)
target_link_libraries(juego PRIVATE Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS juego
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
