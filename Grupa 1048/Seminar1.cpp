#include<iostream>

using namespace std;


//definesc prototipul
void interschimbare(int a, int b);

void interschimbare2(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void interschimbare3(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main() {

	std::cout << "Mesaj afisat la consola!" << endl;
	cout << "Dati un numar: ";
	int x;
	cin >> x;
	cout << "Numarul primit este: " << x << endl;

	int *px;
	px = &x;
	cout << *px << endl;

	int & refx = x;
	refx = 15;
	cout << "x: " << x << endl;
	cout << "refx: " << refx << endl;

	int a = 20, b = 30;
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

void interschimbare(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}