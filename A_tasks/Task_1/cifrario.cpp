#include <iostream>
using namespace std;

int main() {
	
	char x, y, z;
	
	cout << "Inserire tre caratteri: " << endl;
	cin >> x >> y >> z;
	
	// Se non e' una lettera minuscola metto '*'
	// Le prime 23 lettere minuscole vengono incrementate di 3,
	// mentre le ultime 3 lettere vengono decrementate di 23
	x = (x < 'a' || x > 'z') ? '*' : ((x >= 'a' && x <= 'w') ? x+3 : x-23);
	y = (y < 'a' || y > 'z') ? '*' : ((y >= 'a' && y <= 'w') ? y+3 : y-23);
	z = (z < 'a' || z > 'z') ? '*' : ((z >= 'a' && z <= 'w') ? z+3 : z-23);	
	
	// Mostro i 3 caratteri criptati secondo il cifrario di Cesare
	cout << "Cifrario di Cesare: " << x << " " << y << " " << z << endl;
	
	return 0;
}
