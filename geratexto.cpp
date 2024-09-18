#include <iostream>
#include <vector>
#include <string>

int main() {
    // Vetor contendo os números desejados
    std::vector<int> numeros = {3046,3047,3048,3049,3050,3051,3052,3053,3054,3055,3056,3057,3058,3059,3060,3061,3062,3063};  // Você pode adicionar mais números aqui
    
    for (int numero : numeros) {
        // Gerando a linha no formato desejado
        std::cout << "- [x]  [" << numero 
                  << "](https://www.beecrowd.com.br/repository/UOJ_" << numero << ".html) "
                  << "- [Dominó](https://github.com/gnobisP/beecrowd/blob/main/obi2019/bee" 
                  << numero << ".cpp)" << std::endl;
    }
    
    return 0;
}
