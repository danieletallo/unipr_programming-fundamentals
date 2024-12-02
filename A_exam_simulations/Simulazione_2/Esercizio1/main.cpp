#include <iostream>
using namespace std;

void ruota(int x[], int num) {

    for(int i=0; i<num-1; i++) {
        int temp = x[i];
        x[i] = x[num-1];
        x[num-1] = temp;
    }

}


int main() {

    int x[4] = {2, 3, 4, 5};

    ruota(x, 4);

    for(int i=0; i<4; i++) {
        cout << x[i] << " ";
    }

    return 0;
}
