#include <iostream>
using namespace std;

int coincide(int a1[], int a2[], int dim1, int dim2) {

    int coincidenti = 0;

    if(dim1<=dim2) {
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

    int a1[7] = {4, 7, 2 , 3, 8, 9, 11};
    int a2[4] = {3, 7 , 11, 3};

    cout << "Elementi coincidenti: " << coincide(a1, a2, 7, 4);

    return 0;
}
