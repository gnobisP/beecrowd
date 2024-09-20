#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Definir o número de arquivos que deseja criar
    int quantidadeArquivos = 5;  // Exemplo: criar 5 arquivos

    // Loop para criar os arquivos
    for (int i=2448;i<=2470;i++) { 
        // Gerar um nome para cada arquivo
        std::string nomeArquivo = "bee" + std::to_string(i) + ".cpp";

        // Criar o arquivo vazio
        std::ofstream arquivo(nomeArquivo);
        
        // Fecha o arquivo (opcional, o destrutor de ofstream já faz isso)
        arquivo.close();
        
        // Mensagem informando a criação do arquivo
        std::cout << "Arquivo " << nomeArquivo << " criado.\n";
    }

    return 0;
}
