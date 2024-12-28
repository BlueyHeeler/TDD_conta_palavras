// Copyright 2024 <Erick>
#include <iostream>
#include <string>
#include "./conta_palavras.hpp"
#define CATCH_CONFIG_MAIN
#include "./catch.hpp"

TEST_CASE("Testa conta_palavras", "[single-file]") {
    REQUIRE(abrirTXT("input.txt") == "Este texto é o texto que será utilizado");
}
