#include <iostream>
using namespace std;

int main() {

    int x;
    int counter=0;  // per "a"
    int* a = new int[1000];
    int min=0, max=0;

    do {
        cout << "Inserisci un numero positivo: ";
        cin >> x;

        if(x>=0) {
            a[counter] = x;
            counter++;
        }
    } while(x>=0);

    int* b = new int[counter];
    int counter2=0;

    // stampo l'array a, e nel frattempo mi segno il min e il max
    cout << "Array a: ";
    for(int i=0; i<counter; i++) {
        cout << a[i] << " ";
        if(i==0) {
            min = a[i];
            max = a[i];
        } else {
            // controllo se cambiare minimo o massimo
            if(a[i] < min) {
                min = a[i];
            }
            else if(a[i] > max) {
                max = a[i];
            }
        }
    }
    cout << endl;

    // popolo l'array b
    for(int i=0; i<counter; i++) {
        if(a[i]!=min && a[i]!=max) {
            b[counter2] = a[i];
            counter2++;
        }
    }

    //stampo array b;
    cout << "Array b: ";
    for(int i=0; i<counter2; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] b;

    return 0;
}
