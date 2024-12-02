#include <iostream>
using namespace std;


void func ( const int & x ) {
x = x + 5;
}

int main () {
int y = 3;
func ( y );
cout << y << endl ;
}

