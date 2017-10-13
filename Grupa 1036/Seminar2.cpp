#include<iostream>

using namespace std;

struct Hotel {
	int id;
	char* nume;
	char adresa[100];
	char rating;
	bool deschis;
	unsigned int numar_camere;
	float* preturi;
};

void initializare(Hotel* h) {
	cout << "Dati id: ";
	cin >> (*h).id; //la fel cu h->id
	cout << "Dati nume: ";
	char buffer[50];
	cin >> buffer;
	h->nume = new char[strlen(buffer) + 1];
	strcpy(h->nume, buffer);
	cout << "Dati adresa: ";
	//cin >> h->adresa;
	cin.ignore();
	cin.getline(h->adresa, 100);
	cout << "Dati rating: ";
	cin >> h->rating;
	cout << "Este deschis? 1(Da)/0(Nu): ";
	cin >> h->deschis;
	cout << "Dati numar camere: ";
	cin >> h->numar_camere;
	h->preturi = new float[h->numar_camere];
	for (int i = 0; i < h->numar_camere; i++) {
		cout << "Dati pretul pentru camera " << i + 1 << ": ";
		cin >> h->preturi[i];
	}
}

void afisare(Hotel h) {
	cout << "Id: " << h.id << endl;
	cout << "Nume: " << h.nume << endl;
	cout << "Adresa: " << h.adresa << endl;
	cout << "Rating: " << h.rating << endl;
	if (h.deschis == true) {
		cout << "Hotel dat in folosinta." << endl;
	}
	else {
		cout << "Hotel inchis." << endl;
	}
	cout << "Numar camere: " << h.numar_camere << endl;
	for (int i = 0; i < h.numar_camere; i++){
		cout << "Pretul pentru camera " << i + 1 << " este: " << h.preturi[i] << endl;
	}
}

void actualizareNume(Hotel& h) {
	cout << "Dati nume nou: ";
	char nume[50];
	cin >> nume;
	if (h.nume != NULL) {
		delete[] h.nume;
	}
	h.nume = new char[strlen(nume) + 1];
	strcpy(h.nume, nume);
}

float costMediu(Hotel h) {
	float suma = 0;
	for (int i = 0; i < h.numar_camere; i++) {
		suma += h.preturi[i];
	}
	if (h.numar_camere != 0){
		return suma / h.numar_camere;
	}
	else {
		cout << "Atentie! Nicio camera in hotel. " << endl;
		return suma;
	}
}

void main() {
	Hotel h1;
	initializare(&h1);
	afisare(h1);

	Hotel* ph1;
	ph1 = &h1;
	afisare(*ph1);

	cout << "Costul mediu pentru hotelul h1: " << costMediu(h1) << endl;
}