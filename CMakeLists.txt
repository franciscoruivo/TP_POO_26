cmake_minimum_required(VERSION 4.3)
project(TP_POO)

set(CMAKE_CXX_STANDARD 26)

add_executable(TP_POO main.cpp
        Settings.h
        view/Ecra.cpp
        view/Ecra.h
        model/fabrica.cpp
        model/fabrica.h
        model/posicao.cpp
        model/posicao.h
        "controller/Simulador.cpp"
        "controller/Simulador.h"
        model/cordenada.cpp
        model/cordenada.h
        model/carregadordemapa.cpp
        model/carregadordemapa.h
        view/Vistafabrica.cpp
        view/Vistafabrica.h
        controller/teste.cpp
        controller/teste.h
)
