#include <iostream>
using namespace std;

void revert(char s[]) {

    int lungh=0;

    for(int i=0; s[i]!='\0'; i++) {
        lungh++;
    }

    for(int i=0; i<lungh/2; i++) {
        char tmp = s[i];
        s[i] = s[lungh-1-i];
        s[lungh-1-i] = tmp;
    }

}

int main() {

    char s[7] = "hello" ;
    revert( s );
    cout << s ; // stampa " olleh "

    return 0;
}
