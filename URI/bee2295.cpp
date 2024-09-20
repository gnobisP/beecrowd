/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    double A,G,RA,RG;
    cin>>A>>G>>RA>>RG;
    
    double resultA = A/RA;
    double resultB = G/RG;
    if(resultA<resultB)
        cout<<'A'<<endl;
    else
        cout<<'G'<<endl;
    
    return 0;
}
