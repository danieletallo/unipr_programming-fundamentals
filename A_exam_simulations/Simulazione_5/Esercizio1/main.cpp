#include <iostream>
#include <cstring>
using namespace std;

bool palindroma(char stringa[]) {

    bool isPalindroma = true;
    int lunghezza = strlen(stringa);

    if(lunghezza==0)
        isPalindroma = false;
    else {
        for(int i=0; i<lunghezza/2; i++) {
            if(stringa[i] != stringa[lunghezza-i-1]) {
                isPalindroma = false;
                break;
            }
        }
    }


    return isPalindroma;
}

int main() {

    char str[8] = "topopot";

    if(palindroma(str)) {
        cout << "La stringa e' palindroma.";
    }

    return 0;
}
