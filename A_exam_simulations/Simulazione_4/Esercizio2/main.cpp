#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char parola[30] = "";

    cout << "Inserire parola di max 30 caratteri: ";
    cin.getline(parola, 30);

    int lungh_parola = strlen(parola);

    //stampo la parola
    cout << "Parola: " << endl;
    for(int i=0; i<lungh_parola; i++) {
        cout << parola[i];
    }
    cout << endl;

    //verifico palindromia
    bool palindroma = true;
    for(int i=0; i<lungh_parola/2; i++) {
        if(parola[i] != parola[lungh_parola-i-1]) {
            palindroma = false;
            break;
        }
    }

    cout << "La parola " << parola << ((!palindroma) ? " non" : "") << " e' palindroma.";

    return 0;
}
