cmake_minimum_required(VERSION 4.3)
project(TP_POO)

set(CMAKE_CXX_STANDARD 26)

add_executable(TP_POO main.cpp
        Settings.h
        view/Ecra.cpp
        view/Ecra.h
        model/Fabrica.fabrica.cpp
        model/Fabrica.h
        model/posico.cpp
        model/posicao.h
        model/cordenada.cpp
        model/cordenada.h
        model/carregadordemapa.cpp
        model/carregadordemapa.h
        view/Vistafabrica.cpp
        view/Vistafabrica.h
        controller/teste.cpp
        controller/teste.h
        view/VistaFabrica.cpp
        view/VistaFabrica.cpp
        view/VistaFabrica.cpp
)
