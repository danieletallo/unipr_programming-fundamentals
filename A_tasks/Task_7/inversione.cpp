#include <iostream>
using namespace std;

void inverti(int a[], int num_old, int num_new) {
	
	int appoggio = 0;
	
	// scambio tramite "appoggio"	
	appoggio = a[num_old];
	a[num_old] = a[num_new];
	a[num_new] = appoggio;
	
	// se dopo lo scambio num_old è di 1 o 2 piu' grande di num_new, allora non devo continuare a invertire
	if(num_old != num_new + 1 && num_old != num_new + 2) 
		inverti(a, num_old - 1, num_new + 1);
		
}

int main() {
	
	int num, num_inv = 0;
	
	do {
		cout << "Quanti elementi vuoi inserire? ";
		cin >> num;	
	} while(num <= 0);
	
	int a[num];
	
	for(int i = 0; i < num; i++) {
		cout << "Inserire elemento: ";
		cin >> a[i];
	}
	
	// stampo il vecchio array
	for(int i = 0; i < num; i++) 
		cout << a[i] << " ";
	
	// inverto l'array (se ho un solo elemento non ci entro neanche)
	if(num != 1)
		inverti(a, num-1, num_inv);
	
	cout << endl;
	
	//stampo il nuovo array
	for(int i = 0; i < num; i++) 
		cout << a[i] << " ";
	
	return 0;
}
