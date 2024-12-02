#include <iostream>
using namespace std;

int main() {

    int x;
    int* a = new int[1000];
    int conta = 0;

    do {
        cout << "Inserisci un numero intero positivo: ";
        cin >> x;

        if(x>=0) {
            a[conta] = x;
            conta++;
        }
    } while(x>=0);

    for(int i=0; i<conta; i++) {
        cout << a[i];
    }

    int* b = new int[conta];
    int conta2 = 0;

    for(int i=0; i<conta; i++) {
        bool foundAgain = false;

        for(int j=0; j<conta; j++) {
            if(i!=j && a[i] == a[j]) {
                foundAgain = true;
                break;
            }
        }

        if(!foundAgain) {
            b[conta2] = a[i];
            conta2++;
        }

    }

    cout << endl;

    for(int i=0; i<conta2; i++) {
        cout << b[i];
    }

    delete[] a;
    delete[] b;

    return 0;
}
