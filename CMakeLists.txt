cmake_minimum_required(VERSION 3.20)
project(TP_POO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP_POO "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/main.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/Comando.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoAjuda.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoAtribui.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoAvanca.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoCarrega.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoCompra.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoContrata.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoDespede.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoEstado.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoExecuta.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoFabrica.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoFim.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoGrava.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoLposicao.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoMelhora.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoRecupera.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoRoda.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/ComandoVende.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/controller/LeitorComandos.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/Celula.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/Coordenada.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/Fabrica.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/Simulador.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/itens/Item.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/itens/MateriaPrima.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/maquinas/Lancador.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/maquinas/Maquina.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/maquinas/Oficina.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/maquinas/Perfuradora.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/maquinas/Refinaria.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/maquinas/Silo.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/model/maquinas/Transportador.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/util/Random.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/view/Ecra.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/view/Interface.cpp"
        "../../Users/rpess/Downloads/projeto_cp2_codigo (3)/poo_2627_m2_AnaPessoa_2023112690_FranciscoRuivo_2021142024/view/VistaFabrica.cpp"
)

target_include_directories(TP_POO PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/model
        ${CMAKE_SOURCE_DIR}/model/itens
        ${CMAKE_SOURCE_DIR}/model/maquinas
        ${CMAKE_SOURCE_DIR}/view
        ${CMAKE_SOURCE_DIR}/controller
        ${CMAKE_SOURCE_DIR}/util)

target_compile_options(TP_POO PRIVATE -Wall -Wextra -Wpedantic)
