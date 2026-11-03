cmake_minimum_required(VERSION 3.20)
project(TP_POO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP_POO main.cpp
        Settings.h
        controller/Simulador.cpp
        controller/Simulador.h
        view/Ecra.cpp
        view/Ecra.h
        view/VistaFabrica.cpp
        view/VistaFabrica.h
        model/Fabrica.cpp
        model/Fabrica.h
        model/Posicao.cpp
        model/Posicao.h
        model/Coordenada.cpp
        model/Coordenada.h
        util/Random.cpp
        util/Random.h
)

target_include_directories(TP_POO PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/model
        ${CMAKE_SOURCE_DIR}/view
        ${CMAKE_SOURCE_DIR}/controller
        ${CMAKE_SOURCE_DIR}/util)

target_compile_options(TP_POO PRIVATE -Wall -Wextra -Wpedantic)