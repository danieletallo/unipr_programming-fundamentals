#include <iostream>
using namespace std;

int compact(float a[], int num_a, float b[]) {

    float somma = 0;
    float media = 0;

    for(int i=0; i<num_a; i++) {
        somma += a[i];
    }

    media = somma/num_a;

    int cursor = 0;

    for(int i=0; i<num_a; i++) {
        if(a[i] > media) {
            b[cursor] = a[i];
            cursor++;
        }
    }

    return cursor;
}

int main() {

    float a[4] = {1, 1, 1, 2};
    float b[4];

    cout << compact(a, 4, b);



    return 0;
}
