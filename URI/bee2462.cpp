#include <iostream>
using namespace std;
int main()
{
    int chegada1 = 0, saida1 = 0, chegada2 = 0, saida2 = 0;
    int min, hr;

    scanf("%d:%d ", &hr, &min);
    chegada1 += hr * 60 + min;

    scanf("%d:%d ", &hr, &min);
    saida1 += hr * 60 + min;

    scanf("%d:%d ", &hr, &min);
    chegada2 += hr * 60 + min;

    scanf("%d:%d", &hr, &min);
    saida2 += hr * 60 + min;

    int diferenca1,diferenca2;

    if (chegada1 > saida1)//outro dia
        diferenca1 = 1440 - chegada1 + saida1;
    else
        diferenca1 = saida1 - chegada1;

    if (chegada2 > saida2)//outro dia
        diferenca2 = 1440 - chegada2 + saida2;
    else
        diferenca2 = saida2 - chegada2;

    int duracao,fuso;
    if (diferenca1+diferenca2 > 60*24)//máximo 12hrs de voo
        duracao = ((diferenca1+diferenca2)-24*60)/2;
    else
        duracao = (diferenca1+diferenca2) / 2;
    
    if((diferenca1-duracao)>60*24/2)//maximo 12hrs de fuso
        fuso = (diferenca1-duracao-60*24)/60;
    else
        fuso = (diferenca1 - duracao)/60;

    cout<<duracao<<' '<<fuso<<endl;

    return 0;
}