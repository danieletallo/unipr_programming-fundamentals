#include <iostream>
using namespace std;

struct intv{
    int inf;
    int sup;
};

bool add(intv &i, int x) {

    if(x>=i.inf && x<=i.sup) {
        return true;
    } else if(x==i.inf-1) {
        i.inf = x;
        return true;
    } else if(x==i.sup+1) {
        i.sup = x;
        return true;
    }

    //in tutti gli altri casi
    return false;
}

int main() {

    intv i = {3, 7};
    int x;

    cout << "Inserisci x: ";
    cin >> x;

    cout << "True or False: " << add(i, x);

    cout << endl << "Inf e sup: ";
    cout << i.inf << " " << i.sup;
    return 0;
}
