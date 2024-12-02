#include <iostream>
using namespace std;

int main()
{
    int h, i, j;
		
    do {
        cout << "Inserire un valore intero (> 0): " ;
        cin >> h;
        
        if(h<=0)
            cout << "Input errato." << endl;
    } while(h<=0);
    
    for(i=h-1; i>=0; i--) {
        for(j=0; j<h; j++) {
            if(j>=i) 
                cout << "* ";
            else
                cout << "  ";
       } 
        cout << endl;
    } 

    for(i=0; i<h-1; i++) {
        for(j=0; j<h; j++) {
            if(j>i) 
                cout << "* ";
            else 
                cout << "  ";
       } 
        cout << endl;
    } 
    
    return 0;
}
