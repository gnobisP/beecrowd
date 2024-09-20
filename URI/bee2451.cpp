/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int
main ()
{
  int ladoQuadrado;
  cin >> ladoQuadrado;

  char **mapa = new char *[ladoQuadrado];
  for (int i = 0; i < ladoQuadrado; i++)
    {
      mapa[i] = new char[ladoQuadrado];
    }
  int sentido = 0;
  for (int linha = 0; linha < ladoQuadrado; linha++)
    {
      if (sentido == 0)
	{
	  sentido = 1;
	  for (int coluna = 0; coluna < ladoQuadrado; coluna++)
	    {
	      cin >> mapa[linha][coluna];
	    }
	}
      else
	{
	  sentido = 0;
	  for (int coluna = ladoQuadrado - 1; coluna >= 0; coluna--)
	    {
	      cin >> mapa[linha][coluna];
	    }
	}

    }


/*
  cout << "imprimindo" << endl;
  for (int linha = 0; linha < ladoQuadrado; linha++)
    {
      for (int coluna = 0; coluna < ladoQuadrado; coluna++)
	{
	  cout << mapa[linha][coluna];
	}
      cout << endl;
    }*/

  int pontuacaoMax = 0;
  int pontuacao = 0;
  for (int linha = 0; linha < ladoQuadrado; linha++)
    {
      for (int coluna = 0; coluna < ladoQuadrado; coluna++)
	{
	  switch (mapa[linha][coluna])
	    {
	    case '.':
	      break;
	    case 'A':
	      pontuacao = 0;
	      break;
	    case 'o':
	      pontuacao++;
	      break;
	    }
	  if (pontuacao > pontuacaoMax)
	    {
	      pontuacaoMax = pontuacao;
	    }
	}

    }
    cout << pontuacaoMax<<endl;

  return 0;
}
