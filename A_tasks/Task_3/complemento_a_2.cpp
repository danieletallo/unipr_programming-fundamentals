#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int nBit, operaz, numDecimale=0;
	int i;

	do {
		cout << "Bits per il numero in complemento a 2: ";
		cin >> nBit;
		
		if(nBit < 2) 
			cout << "Errore! Inserire un valore >= 2 !" << endl;
	} while(nBit < 2);

	int compl2[nBit];
	
	for(i = nBit-1; i >= 0; i--) {
		do {
			cout << "Inserisci il bit nella posizione " << i << ": ";
			cin >> compl2[i];
		} while(compl2[i] != 0 && compl2[i] != 1);
	}
	
	do {
		cout << "Operazione (0 - Stampa Binario, 1 - Converti in Decimale, 2 - Calcola Opposto): ";
		cin >> operaz;
		
		if(operaz < 0 || operaz > 2)
			cout << "Errore!" << endl;
	} while(operaz < 0 || operaz > 2);
	
	switch(operaz) {
		
		// stampa binario
		case 0:
			cout << "Numero binario: ";
			
			for(i = nBit-1; i >= 0; i--) 
				cout << compl2[i];
			
			break;
			
		// converti in decimale
		case 1:
			if(compl2[nBit-1] == 0) {
				// converto in decimale
				for(i = 0; i < nBit; i++)
					numDecimale += (compl2[i] * pow(2, i));					
			}
			else {
				// se il bit piu' significativo e' negativo allora sottraggo 1 e poi inverto le cifre
				// sottraggo 1: parto del meno significativo, se 0 lo trasformo in 1, se 1 lo trasformo in 0; mi fermo quando incontro il primo 1
				for(i = 0; i < nBit; i++) {
					if(compl2[i] == 0)
						compl2[i] = 1;
					else {
						compl2[i] = 0;
						break;
					}
				}
				// ribalto i bit
				for(i = 0; i < nBit; i++) {
					if(compl2[i] == 0)
						compl2[i] = 1;
					else 
						compl2[i] = 0;
				}	
				// converto in decimale (negativo!)
				for(i = 0; i < nBit; i++)
					numDecimale += (compl2[i] * pow(2, i));	
				numDecimale = -numDecimale;
			}
			
			cout << "Numero decimale: " << numDecimale;
			
			break;
			
		// calcola opposto
		case 2:
			if(compl2[nBit-1] == 0) {
				// ribalto i bit
				for(i = 0; i < nBit; i++) {
					if(compl2[i] == 0)
						compl2[i] = 1;
					else 
						compl2[i] = 0;
				}	
				// aggiungo 1: parto dal meno significativo, se 0 lo trasformo in 1, se 1 lo trasformo in 0; mi fermo quando incontro il primo 0
				for(i = 0; i < nBit; i++) {
					if(compl2[i] == 0) {
						compl2[i] = 1;
						break;
					}
					else 
						compl2[i] = 0;
				}			
			}
			else {
				// se il bit piu' significativo e' negativo allora sottraggo 1 e poi inverto le cifre
				// sottraggo 1: parto del meno significativo, se 0 lo trasformo in 1, se 1 lo trasformo in 0; mi fermo quando incontro il primo 1
				for(i = 0; i < nBit; i++) {
					if(compl2[i] == 0)
						compl2[i] = 1;
					else {
						compl2[i] = 0;
						break;
					}
				}
				// ribalto i bit
				for(i = 0; i < nBit; i++) {
					if(compl2[i] == 0)
						compl2[i] = 1;
					else 
						compl2[i] = 0;
				}
				
				// se dopo la conversione da negativo a positivo il bit più significativo è a 1, allora è overflow
				if(compl2[nBit-1] == 1) {
					cout << "Overflow!";
					break;
				}
			}
			
			cout << "Opposto: ";
			
			for(i = nBit-1; i >= 0; i--) 
				cout << compl2[i];
			
			break;
	}
	
	return 0;
}
