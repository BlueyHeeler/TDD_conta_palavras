// Copyright 2024 <Erick>
#include "./conta_palavras.hpp"
#include <iostream>
#include <string>
#include <fstream>

std::string abrirTXT(std::string path) {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open())
        return "Erro ao abrir o arquivo!\n";

    std::string frase;
    std::string linha;
    while (std::getline(inputFile, linha))
        frase += linha;

    inputFile.close();
    return frase;
}



