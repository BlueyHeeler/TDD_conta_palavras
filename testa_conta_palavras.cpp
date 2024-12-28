// Copyright 2024 <Erick>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "./conta_palavras.hpp"
#define CATCH_CONFIG_MAIN
#include "./catch.hpp"

TEST_CASE("Teste de abrir arquivo") {
    REQUIRE(abrirTXT("input.txt") == "Este texto é o texto que será utilizado");
}

TEST_CASE("Teste de iteracao") {
    std::vector<std::string> esperado = {"Este", "texto", "é", "o",
        "texto", "que", "será", "utilizado"};
        REQUIRE(iteraTXT(abrirTXT("input.txt")) == esperado);
}

TEST_CASE("Teste de mapping") {
    std::vector<std::string> base = {"Este", "texto", "é", "o",
        "texto", "que", "será", "utilizado"};
    std::string esperado = "Este: 1\no: 1\nque: 1\nserá: 1"
                            "\ntexto: 2\nutilizado: 1\né: 1\n";
    REQUIRE(mapping(base) == esperado);
}

TEST_CASE("Teste de ordenacao do vector") {
    std::vector<std::string> base={"Este", "texto", "é", "o",
                                   "texto", "que", "será", "utilizado"};
    std::vector<std::string> esperado ={"Este", "o", "que",
                                        "será", "texto", "texto", "utilizado", "é"};
    REQUIRE(ordenar(base) == esperado);
}

