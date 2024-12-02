#include <iostream>
using namespace std;

int compatta(int a[], int n, int b[]) {
    int counter_b = 0;
    bool trovato;

    //scorro A
    for(int i=0; i<n; i++) {
        trovato = false;
        //scorro B, se lo trovo non lo inserisco e non incremento
        for(int j=0; j<counter_b; j++) {
            if(a[i] == b[j]) {
                trovato = true;
                break;
            }
        }
        if(!trovato) {
            b[counter_b] = a[i];
            counter_b++;
        }
    }
    return counter_b;
}


int main() {
    int a[9] = {1 , 2 , 7 , 1 , 2 , 4 , 1 , 7 , 5};
    int b[9];

    cout << "Inseriti: " << compatta(a, 9, b);

    return 0;
}
