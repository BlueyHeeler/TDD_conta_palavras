// Copyright 2024 <Erick>
#include "./conta_palavras.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

std::vector<std::string> iteraTXT(std::string frase) {
    std::vector<std::string> ans;
    std::string palavra;
    auto it = frase.begin();

    while (it != frase.end()) {
        // Ignorar espaços em branco
        while (it != frase.end() && std::isspace(*it)) {
            ++it;
        }

        // Construir palavra até o próximo espaço
        palavra.clear();
        while (it != frase.end() && !std::isspace(*it)) {
            palavra += *it;
            ++it;
        }

        if (!palavra.empty()) {
            ans.push_back(palavra);
        }
    }

    return ans;
}



