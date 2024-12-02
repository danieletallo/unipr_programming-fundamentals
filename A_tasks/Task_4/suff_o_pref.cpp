#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
	char a[101], b[101], c[101];
	
	do{
		cout << "Inserire la prima parola: ";
		cin.getline(a, 101);
		if(strcmp(a, "exit") == 0) 
			break;
		
		cout << "Inserire la seconda parola: ";
		cin.getline(b, 101);
		if(strcmp(b, "exit") == 0) 
			break;
				
		// metto nell'array "a" la stringa piu' corta così faccio i controlli su di essa
		if(strlen(b) < strlen(a)) {
			strcpy(c, b); // "appoggio" b
			strcpy(b, a);
			strcpy(a, c);
		}
		
		char pref[strlen(a)+1];
		char suff[strlen(a)+1];
		
		//popolo l'array con la prima parte di b lunga quanto a
		for(int i = 0; i < strlen(a); i++) 
			pref[i] = b[i];	
		pref[strlen(a)] = '\0';		

		int j=0;
		//popolo l'array con la parte finale di b lunga quanto a
		for(int i = strlen(b)-strlen(a); i < strlen(b); i++) {
			suff[j] = b[i];		
			j++;
		}
		suff[strlen(a)] = '\0';
		
		//controllo se sono uguali, altrimenti controllo prefisso e suffisso
		if(strcmp(a, b) == 0) {
			cout << "Le due parole sono uguali." << endl;
			cout << "Reverse: ";
			for(int i = strlen(a)-1; i >= 0; i--) {
				cout << a[i];
			}
			cout << endl;
		} else {
			if(strcmp(a, pref) == 0) {
				cout << "La parola ";
				for(int i = 0; a[i] != '\0'; i++)
					cout << a[i];
				cout << " e' prefisso di ";
				for(int i = 0; b[i] != '\0'; i++)
					cout << b[i];
				cout << endl;	
			}	

			if(strcmp(a, suff) == 0) {
				cout << "La parola ";
				for(int i = 0; a[i] != '\0'; i++)
					cout << a[i];
				cout << " e' suffisso di ";
				for(int i = 0; b[i] != '\0'; i++)
					cout << b[i];	
				cout << endl;
			}	
		}
		cout << endl;
	} while(true);
	
	cout << "Addio!" << endl;
	
	return 0;
}
