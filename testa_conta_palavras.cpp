// Copyright 2024 <Erick>
#include "conta_palavras.hpp"
#include <iostream>
#include <string>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Testa conta_palavras", "[single-file]" ) {

    REQUIRE(abrirTXT("input.txt") == "Este texto é o texto que será utilizado");
}
