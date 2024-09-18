#include <iostream>
#include <vector>
#include <string>

int main() {
    // Vetor contendo os números desejados
    std::vector<int> numeros = {2227,2228,2229,2230,2231,2232};  // Você pode adicionar mais números aqui
    
    for (int numero : numeros) {
        // Gerando a linha no formato desejado
        std::cout << "- [x]  [" << numero 
                  << "](https://www.beecrowd.com.br/repository/UOJ_" << numero << ".html) "
                  << "- [Solution](https://github.com/gnobisP/beecrowd/blob/main/obi2019/bee" 
                  << numero << ".cpp)" << std::endl<<std::endl;
    }
    
    return 0;
}
