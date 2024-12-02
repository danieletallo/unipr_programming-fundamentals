#include <iostream>
#include <cstring>
using namespace std;

struct contatto {
	char nome[25];
	char cognome[25];
	char numeroTel[11];
};

int main() {
	contatto rubrica[100];
	int scelta, cont = 0;
	char nomeDel[25], cognomeDel[25];
	bool cancellati, numTel_correct;
	
	cout << "*** Rubrica ***" << endl;
	
	do {
		do {
			cout << "1 - Visualizza rubrica" << endl;
			cout << "2 - Inserisci contatto" << endl;
			cout << "3 - Cancella contatto" << endl;
			cout << "4 - Esci" << endl;
		
			cin >> scelta;
			cin.ignore();
			
			if(scelta < 1 || scelta > 4) 
				cout << "Inserire un numero da 1 a 4!" << endl;
		} while(scelta < 1 || scelta > 4);
		
		switch(scelta) {
		
			case 1:
				if(cont==0)
					cout << "Rubrica vuota!" << endl;
				else {
					for(int i = 0; i < cont; i++) {
						cout << rubrica[i].nome << " ";
						cout << rubrica[i].cognome << " ";
						cout << rubrica[i].numeroTel << " " << endl;
					}
				}
				break;
		
			case 2:
				contatto c;
				
				cout << "Inserisci il nome del contatto da aggiungere: ";
				cin.getline(c.nome, 25);
				cout << "Inserisci il cognome del contatto da aggiungere: ";
				cin.getline(c.cognome, 25);
				
				do {
					numTel_correct = true;
					cout << "Inserisci il numero del contatto da aggiungere: ";
					cin.getline(c.numeroTel, 11);
					
					// verifico la correttezza del numero di telefono, dev'essere lungo 10 e contenente solo numeri
					if(strlen(c.numeroTel) == 10) {
						for(int i = 0; i < strlen(c.numeroTel); i++) {
							if(c.numeroTel[i] < '0' || c.numeroTel[i] > '9') {
								numTel_correct = false;							
							}
						}	
					} else {
						numTel_correct = false;
					}
					
					if(numTel_correct == false)
						cout << endl << "Devi inserire un numero composto da sole cifre e lungo 10!" << endl;
				} while(numTel_correct == false);
				
				rubrica[cont] = c;
				cont++;
			
				cout << endl << "Contatto aggiunto!" << endl;
				break;
		
			case 3:
				cout << "Inserisci il nome del contatto da cancellare: ";
				cin.getline(nomeDel, 25);
				cout << "Inserisci il cognome del contatto da cancellare: ";
				cin.getline(cognomeDel, 25);
			
				cancellati = false;  // la dichiaro a true dentro l'if successivo, mi serve per stampare il messaggio una volta sola
				
				for(int i = 0; i < cont; i++) {
					if(strcmp(rubrica[i].nome, nomeDel) == 0 &&
					   strcmp(rubrica[i].cognome, cognomeDel) == 0) {
					   	
						// se tramite nome e cognome ho trovato il contatto da eliminare
						// allora "scalo" tutti i contatti successivi alla pos. precedente in modo da rimpiazzarlo
						// e decremento il "cont" così poi non stampo l'ultimo contatto nella scelta 1 (grazie al for che arriva a i<cont)
						// e inoltre potrò usare nuovamente quella posizione per inserire un nuovo contatto
						for(int j = i; j < cont; j++) {
							strcpy(rubrica[j].nome, rubrica[j+1].nome);
							strcpy(rubrica[j].cognome, rubrica[j+1].cognome);
							strcpy(rubrica[j].numeroTel, rubrica[j+1].numeroTel);	
						}
						cont--;
						i--;  // decremento anche "i" perche' in caso di contatti con stesso nome e cognome, potrebbe dar problemi e skipparne alcuni
						cancellati = true;
					} 
				}
				if(cancellati)
					cout << endl << "Contatto/i cancellato/i!" << endl;;
				break;
						
			case 4: 
				cout << "Addio!";
				break;
		}
	} while (scelta != 4);
	
	return 0;
}
