#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void separa(char s[], char alpha[], char num[], int& nAlpha, int& nNum) {
	
	for(int i = 0; i < strlen(s); i++) {
		
		if(isalpha(s[i])) {
			alpha[nAlpha] = s[i];
			nAlpha++;
		} else if(isdigit(s[i])) {
			num[nNum] = s[i];
			nNum++;
		}
	}
	return;
}

int main() {
	
	char str[101];
	char SAlpha[100];
	char SNum[100];
	int lunghA=0, lunghN=0;
	
	cout << "Inserisci una stringa: ";
	cin.getline(str, 101);
	
	separa(str, SAlpha, SNum, lunghA, lunghN);
	
	cout << "Caratteri alfabetici: " << endl;
	for(int i = 0; i < lunghA; i++) {
		cout << SAlpha[i] << " ";
	}
	
	cout << endl << "Caratteri numerici: " << endl;
	for(int i = 0; i < lunghN; i++) {
		cout << SNum[i] << " ";
	}
	
	return 0;
}
