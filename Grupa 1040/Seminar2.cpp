#include<iostream>
using namespace std;
void interschimbare(int x, int y);

void interschimbare2(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void interschimbare3(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

struct Hotel {
	int id;
	char* nume;
	char adresa[100];
	char rating;
	bool deschis;
	unsigned int numar_camere;
	float* preturi;
};

void initializareHotel(Hotel* h) {
	cout << "Dati id: ";
	cin >> (*h).id;
	//cin >> h->id;
	cout << "Dati nume: ";
	char buffer[100];
	cin >> buffer;
	h->nume = new char[strlen(buffer) + 1];
	strcpy(h->nume, buffer);
	cout << "Dati adresa: ";
	cin.ignore();
	cin.getline(h->adresa,100);
	cout << "Dati rating: ";
	cin >> h->rating;
	cout << "Este deschis? 1(Da)/0(Nu): ";
	cin >> h->deschis;
	cout << "Dati numarul de camere: ";
	cin >> h->numar_camere;
	h->preturi = new float[h->numar_camere];
	for (int i = 0; i < h->numar_camere; i++){
		cout << "Dati pretul pentru camera " << i + 1 << ": ";
		cin >> h->preturi[i];
	}

}

void afisare(Hotel h) {
	cout << "Id: " << h.id << endl;
	cout << "Nume: " << h.nume << endl;
	cout << "Adresa: " << h.adresa << endl;
	cout << "Rating: " << h.rating << endl;
	if (h.deschis == true){
		cout << "Hotel este dat in folosinta." << endl;
	}
	else {
		cout << "Hotelul este inchis." << endl;
	}
	cout << "Numar camere: " << h.numar_camere << endl;
	for (int i = 0; i < h.numar_camere; i++)
	{
		cout << "\t Pretul camerei " << i + 1 << "este: " << h.preturi[i] << endl;
	}
}

void main() {
	int a = 10, b = 20;
	interschimbare(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	interschimbare2(&a, &b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	interschimbare3(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;



	//exemplu Hotel
	Hotel h1;
	initializareHotel(&h1);
	afisare(h1);

	Hotel* ph1 = &h1;
	afisare(*ph1);


}

void interschimbare(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}