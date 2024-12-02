#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char s1[100];
    char s2[100];

    cout << "Inserisci 1^ stringa: ";
    cin.getline(s1, 100);

    cout << "Inserisci 2^ stringa: ";
    cin.getline(s2, 100);

    int lungh_s1 = strlen(s1);
    int lungh_s2 = strlen(s2);

    // stampo s1

    for(int i=0; i<lungh_s1; i++) {
        cout << s1[i];
    }
    cout << endl;

    for(int i=0; i<lungh_s2; i++) {
        cout << s2[i];
    }
    cout << endl;

    //controllo se s2 e' anagramma di s1
    //prima di tutto controllo la lunghezza
    if(lungh_s1==lungh_s2) {

        //appoggio la stringa s2 su s_app cosi lavoro su quest'ultima (posso "sporcarla")
        char s_app[100];
        strcpy(s_app, s2);

        for(int i=0; i<lungh_s1; i++) {

            for(int j=i; j<lungh_s1; j++) {
                //trovato
                if(s1[i] == s_app[j]) {
                    //faccio scambio
                    char appoggio = s_app[j];
                    s_app[j] = s_app[i];
                    s_app[i] = appoggio;
                    break;
                }
            }
        }

        if(strcmp(s1, s_app) == 0) {
            cout << "La stringa " << s2 << " e' anagramma della stringa " << s1 ;
        }

    }


    return 0;
}
