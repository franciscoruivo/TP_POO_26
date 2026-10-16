cmake_minimum_required(VERSION 3.20)
project(TP_POO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP_POO main.cpp
        Settings.h
        view/Ecra.cpp
        view/Ecra.h
        model/Fabrica.cpp
        model/Fabrica.h
        model/Posicao.cpp
        model/Posicao.h
        model/Coordenada.cpp
        model/Coordenada.h
        model/CarregadorMapa.cpp
        model/CarregadorMapa.h
        view/VistaFabrica.cpp
        view/VistaFabrica.h
        model/Terreno.h
        model/Terreno.cpp
)

target_include_directories(TP_POO PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/model
        ${CMAKE_SOURCE_DIR}/view)