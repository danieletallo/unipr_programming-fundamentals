#include <iostream>
using namespace std;

int coincide(int a1[], int a2[], int dim1, int dim2) {
    int coincidenti = 0;

    if(dim1 <= dim2) {
        for(int i=0; i<dim1; i++) {
            if(a1[i] == a2[i])
                coincidenti++;
        }
    } else {
        for(int i=0; i<dim2; i++) {
            if(a1[i] == a2[i])
                coincidenti++;
        }
    }

    return coincidenti;
}

int main() {

    int a1[7] = {4, 7, 6, 8, 9, 10, 11};
    int a2[4] = {5, 8 , 6, 4};

    cout << coincide(a1, a2, 7, 4);

    return 0;
}
