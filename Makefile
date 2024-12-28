# Definindo o compilador e as flags
CC = g++
CXXFLAGS = -std=c++11 -Wall
OBJ_DIR = coverage

# Alvo default
all: testa_conta_palavras

# Compilar e rodar o programa
testa_conta_palavras: conta_palavras.o testa_conta_palavras.cpp conta_palavras.hpp
	$(CC) $(CXXFLAGS) conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras

# Gerar o objeto da conta_palavras
conta_palavras.o: conta_palavras.cpp conta_palavras.hpp
	$(CC) $(CXXFLAGS) -c conta_palavras.cpp

# Rodar os testes
test: testa_conta_palavras
	./testa_conta_palavras

# Verificar o código com cpplint
cpplint: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	cpplint --filter=-whitespace/tab testa_conta_palavras.cpp conta_palavras.cpp

# Cobertura de código com gcov
gcov: conta_palavras.cpp testa_conta_palavras.cpp conta_palavras.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -o $(OBJ_DIR)/conta_palavras.o -c conta_palavras.cpp
	$(CC) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -o $(OBJ_DIR)/testa_conta_palavras $(OBJ_DIR)/conta_palavras.o testa_conta_palavras.cpp
	./$(OBJ_DIR)/testa_conta_palavras
	gcov -o $(OBJ_DIR) *.cpp

# Depuração com gdb
debug: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	$(CC) $(CXXFLAGS) -g -c conta_palavras.cpp
	$(CC) $(CXXFLAGS) -g conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	gdb testa_conta_palavras

# Verificar com cppcheck
cppcheck: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	cppcheck --enable=warning .

# Verificar com Valgrind
valgrind: testa_conta_palavras
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_conta_palavras

# Limpar arquivos temporários
clean:
	@if [ "$(OS)" = "Windows_NT" ]; then \
		del /f /q *.o *.exe *.gc* 2>nul || exit 0; \
	else \
		rm -f *.o *.exe *.gc*; \
	fi

	
	
