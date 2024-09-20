#include <iostream>
#include <vector>
#include <string>

int main() {
    // Vetor contendo os números desejados
    std::vector<int> numeros = {2293,2294,2295,2296,2297,2298,2299,2300,2301};  // Você pode adicionar mais números aqui
    
    for (int numero : numeros) {
        // Gerando a linha no formato desejado
        std::cout << "- [x]  [" << numero 
                  << "](https://www.beecrowd.com.br/repository/UOJ_" << numero << ".html) "
                  << "- [Solution](https://github.com/gnobisP/beecrowd/blob/main/URI/bee" 
                  << numero << ".cpp)" << std::endl<<std::endl;
    }
    
    return 0;
}
