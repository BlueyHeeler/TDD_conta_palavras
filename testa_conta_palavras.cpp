// Copyright 2024 <Erick>
#include <iostream>
#include <string>
#include <vector>
#include "./conta_palavras.hpp"
#define CATCH_CONFIG_MAIN
#include "./catch.hpp"

TEST_CASE("Testa conta_palavras", "[single-file]") {
    REQUIRE(abrirTXT("input.txt") == "Este texto é o texto que será utilizado");

    std::vector<std::string> esperado = {"Este","texto","é","o","texto","que","será","utilizado"};
    REQUIRE(iteraTXT(abrirTXT("input.txt")) == esperado);
}
