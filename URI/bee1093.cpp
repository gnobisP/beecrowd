#include<bits/stdc++.h>
using namespace std;

int main() {
    while (1) {
        int ev1, ev2, at, d;
        cin >> ev1 >> ev2 >> at >> d;

        if (ev1 == 0 && ev2 == 0 && at == 0 && d == 0) {
            break;
        }

        // Gambler's Ruin
        int aux = ev1;
        ev1 = 0;
        while (aux > 0) {
            aux -= d;
            ev1 += 1;
        }

        aux = ev2;
        ev2 = 0;
        while (aux > 0) {
            aux -= d;
            ev2 += 1;
        }

        double probability;
        if (at == 3) {
            probability = (double)(ev1) / (double)(ev1 + ev2);
        } else {
            double qp = (1 - (6 - at) / 6.0);
            qp = (1 - qp) / qp;
            probability = (1 - pow(qp, ev1)) / (1 - pow(qp, ev1 + ev2));
        }

        cout << fixed << setprecision(1) << (probability * 100) << endl;
    }

    return 0;
}