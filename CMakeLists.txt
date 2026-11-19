cmake_minimum_required(VERSION 3.20)
project(TP_POO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP_POO main.cpp
        controller/Comando.cpp
        controller/ComandoAjuda.cpp
        controller/ComandoAtribui.cpp
        controller/ComandoAvanca.cpp
        controller/ComandoCarrega.cpp
        controller/ComandoCompra.cpp
        controller/ComandoContrata.cpp
        controller/ComandoDespede.cpp
        controller/ComandoEstado.cpp
        controller/ComandoExecuta.cpp
        controller/ComandoFabrica.cpp
        controller/ComandoFim.cpp
        controller/ComandoGrava.cpp
        controller/ComandoLposicao.cpp
        controller/ComandoMelhora.cpp
        controller/ComandoRecupera.cpp
        controller/ComandoRoda.cpp
        controller/ComandoVende.cpp
        controller/LeitorComandos.cpp
        model/Celula.cpp
        model/Coordenada.cpp
        model/Fabrica.cpp
        model/maquinas/Lancador.cpp
        model/maquinas/Maquina.cpp
        model/itens/MateriaPrima.cpp
        model/maquinas/Oficina.cpp
        model/maquinas/Perfuradora.cpp
        model/maquinas/Refinaria.cpp
        model/maquinas/Silo.cpp
        model/Simulador.cpp
        model/maquinas/Transportador.cpp
        util/Random.cpp
        view/Ecra.cpp
        view/Interface.cpp
        view/VistaFabrica.cpp
)

target_include_directories(TP_POO PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/model
        ${CMAKE_SOURCE_DIR}/view
        ${CMAKE_SOURCE_DIR}/controller
        ${CMAKE_SOURCE_DIR}/util)

target_compile_options(TP_POO PRIVATE -Wall -Wextra -Wpedantic)