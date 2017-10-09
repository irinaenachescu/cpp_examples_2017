#include<iostream>

using namespace std;

void main() {
	std::cout << "Mesaj afisat la consola!";
	cout << "Dati un numar: " << endl;
	int x;
	cin >> x;
	cout << "x: " << x << endl;

	cout << "Dimensiunea in bytes a lui x este: " << sizeof(x) << endl;
	cout << "Dimensiunea in bytes a unui char este: " << sizeof(char) << endl;

	int *px = &x;
	cout << "Pointerul: " << *px << endl;



}