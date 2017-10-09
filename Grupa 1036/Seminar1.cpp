#include<iostream>
using namespace std;


void interschimbare(int x, int y);

void interschimbare2(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

void interschimbare3(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main(){

	std::cout << "Un mesaj la consola!";
	cout << "Dati un numar: ";
	int x;
	cin >> x;
	cout << "Numarul primit este: " << x << endl;

	cout << "Dimensiunea lui x: " << sizeof(x) << " bytes." << endl;
	cout << "Dimensiunea unui char: " << sizeof(char) << " bytes." << endl;

	int * px = &x;
	cout << "Pointer px: " << *px << endl;

	int a = 100, b = 200;
	int aux = a;
	a = b;
	b = aux;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	interschimbare(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	interschimbare2(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	interschimbare3(&a, &b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}

void interschimbare(int x, int y){
	int temp = x;
	x = y;
	y = temp;
}