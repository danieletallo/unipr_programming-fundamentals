#include <iostream>
using namespace std;

int main() {
	
	int* A[1000];
	int* var;
	int x;
	bool trovato, deallocato;
	int cursor = 0, numVar = 0;  // cursor sara' il contatore per l'array, numVar invece il numero di variabili dinamiche "istanziate"
	
	do {
		cout << "Inserisci un numero positivo: ";
		cin >> x;
		
		trovato = false;
		
		if(x >= 0) {
			if(cursor==0) {
				var = new int(x);
				A[cursor] = var;
				numVar++;
			}
			else {
				// mi scorro l'array per vedere se esiste gia' un puntatore a quel numero intero
				// in tal caso inserisco nuovamente quell'indirizzo
				for(int i=0; i<cursor; i++) {
					if (*A[i] == x) {
						A[cursor] = A[i];
						trovato = true;
						break;
					}	
				}
			
				// se non l'ho trovato 
				if(!trovato) {
					var = new int(x);
					A[cursor] = var;
					numVar++;
				}
			}
			
			cursor++;
		}
	} while(x >= 0);

	
	// Stampo numero variabili
	cout << "Allocate " << numVar << " variabili" << endl;
	
	// Stampo le variabili
	for(int i=0; i<cursor; i++) {
		cout << *A[i] << " ";		
	}
	
	// Dealloco le variabili
	for(int i=0; i<cursor; i++) {
		deallocato = false;
		
		for(int j=0; j<i; j++) {
			if(A[j] == A[i]) {
				deallocato = true;
				break;
			}
		}
		
		if(!deallocato)
			delete A[i];
	}
	
	return 0;
}
