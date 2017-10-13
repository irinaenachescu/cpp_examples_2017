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
	cin >> (*h).id; //h->id;
	cout << "Dati nume: ";
	char buffer[50];
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
		cout << "Hotelul primeste vizitatori." << endl;
	}
	else {
		cout << "Hotelul este inchis." << endl;
	}
	cout << "Numar camere: " << h.numar_camere << endl;
	for (int i = 0; i < h.numar_camere; i++){
		cout << "\t Pretul pentru camera " << i + 1 << " este:" << h.preturi[i] << endl;
	}
}

void actualizareNume(Hotel& h) {
	cout << "Dati noul nume: ";
	char temp[50];
	cin >> temp;
	if (h.nume != NULL) {
		delete[] h.nume;
	}
	h.nume = new char[strlen(temp) + 1];
	strcpy(h.nume, temp);
}

void main() {
	Hotel h1;
	initializare(&h1);
	afisare(h1);

	Hotel* ph1;
	ph1 = &h1;
	afisare(*ph1);

	actualizareNume(h1);
	afisare(h1);



}