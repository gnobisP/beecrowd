#include <iostream>

using namespace std;

int main()
{
    int p,r;
    
    cin >> p;
    cin >> r;

    if(p == 0){
        cout << 'C';
    }else{
        if(r == 0)
            cout << 'B';
        else
            cout << 'A';
    }
    cout<<endl;
    return 0;
}