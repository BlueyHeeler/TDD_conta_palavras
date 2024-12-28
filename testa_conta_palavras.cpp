// Copyright 2024 <Erick>
#include <iostream>
#include <string>
#include <vector>
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

    std::map<std::string, int> esperado = {
        {"é", 1},
        {"este", 1},
        {"o", 1},
        {"que", 1},
        {"será", 1},
        {"texto", 2},
        {"utilizado", 1}
    };

    REQUIRE(mapping(base) == esperado);
}

